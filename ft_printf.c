/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 21:31:22 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_ptrtostr(void *ptr)
{
	size_t buffersize;
	uintptr_t ptrval;
	char *ptrstr;
	char *hex;

	if (ptr == NULL)
		return (ft_strdup("(nil)"));
	hex = "0123456789abcdef";
	ptrval = (uintptr_t)ptr;
	buffersize = 0;
	while (ptrval != 0)
	{
		ptrval /= 16;
		buffersize++;
	}
	ptrval = (uintptr_t)ptr;
	ptrstr = ft_calloc(buffersize + 3, sizeof(char));
	if (!ptrstr)
		return NULL;
	ptrstr[0] = '0';
	ptrstr[1] = 'x';
	while (buffersize > 0)
	{
		ptrstr[buffersize-- + 1] = hex[ptrval % 16];
		ptrval /= 16;
	}
	return ptrstr;
}

char *ft_printf_zeropaddedstr(size_t zeros, char *str)
{
	char *temp;
	size_t i;
	char *result;
	if (zeros == 0)
		return (ft_strdup(str));
	temp = ft_calloc(zeros + 1, sizeof(char));
	if (!temp)
		return NULL;
	i = 0;
	while (i < zeros)
		temp[i++] = '0';
	result = ft_strjoin(temp, str);
	free(temp);
	return result;
}

static char	*ft_printf_getargstr(va_list args, t_vars *vars)
{
	char *str;
	const char conv = vars->conversion;

	if (conv == conv_c)
	{
		str = ft_calloc(1, 2);
		if (!str)
			return NULL;
		*str = (char)va_arg(args, int);
		return str;
	}
	if (conv == conv_s)
	{	
		str = va_arg(args, char*);
		if (str == NULL)
		{
			str = ft_strdup("(null)");
			if (vars->flag & flag_precision && vars->precision < ft_strlen(str))
			{
				free(str);
				str = ft_strdup("");
			}
		}
		else
		{
			char *temp = ft_strdup(str);
			if (vars->flag & flag_precision)
			{
				if (vars->precision > 0)
					str = ft_substr(temp, 0, vars->precision);
				else if (vars->precision == 0)
					str = ft_strdup("");
			}
			else
				str = ft_strdup(temp);
			free(temp);
		}
		return str;
	}
	if (conv == conv_p)
	{
		return ft_ptrtostr(va_arg(args, void*));
	}
	if (conv == conv_d || conv == conv_i)
	{
		char *temp;
		int x = va_arg(args, int);
		if (x == 0 && vars->flag & flag_precision && vars->precision == 0)
			return (ft_strdup(""));		
		if (x < 0)
		{
			vars->isnegsigned = 1;
			temp = ft_itoa(ft_abs(x));
			if (*temp == '-') // int_min case :clown:
			{
				char *temp2 = temp;
				temp = ft_strtrim(temp, "-");
				free(temp2);
			}
		}
		else
			temp = ft_itoa(x);
		if (vars->flag & flag_precision && vars->precision > ft_strlen(temp))
		{
			str = ft_printf_zeropaddedstr(vars->precision - ft_strlen(temp), temp);
			free(temp);
		}
		else
			str = temp;
		if ((vars->flag & flag_plus || vars->flag & flag_space) && !vars->isnegsigned)
		{
			temp = str;
			if (vars->flag & flag_plus)
				str = ft_strjoin("+", temp);
			else
				str = ft_strjoin(" ", temp);
			free(temp);
		}
		return str;
	}
	if (conv == conv_u)
	{
		char *temp;
		int x = va_arg(args, unsigned int);
		if (x == 0 && vars->flag & flag_precision && vars->precision == 0)
			return (ft_strdup(""));
		temp = ft_uitoa(x);
		if (vars->flag & flag_precision && vars->precision > ft_strlen(temp))
		{
			str = ft_printf_zeropaddedstr(vars->precision - ft_strlen(temp), temp);
			free(temp);
		}		
		else
			str = temp;
		return str;
	}
	if (conv == conv_x || conv == conv_X)
	{
		char *temp;
		int x;
		x = va_arg(args, unsigned int);
		if (x == 0 && vars->flag & flag_precision && vars->precision == 0)
			return (ft_strdup(""));		
		if (conv == conv_x)
			temp = ft_uitoa_base(x, "0123456789abcdef");
		else
			temp = ft_uitoa_base(x, "0123456789ABCDEF");
		temp = ft_strrev(temp, ft_strlen(temp));
		if (vars->flag & flag_precision && vars->precision > ft_strlen(temp))
		{
			str = ft_printf_zeropaddedstr(vars->precision - ft_strlen(temp), temp);
			free(temp);
		}		
		else
			str = temp;
		// handle altform flag
		if (vars->flag & flag_pound && x != 0)
		{
			temp = str;
			if(conv == conv_x)
				str = ft_strjoin("0x", temp);
			else
				str = ft_strjoin("0X", temp);
			free(temp);
		}
		return str;
	}
	if (conv == conv_percent)
	{
		str = ft_strdup("%");
		return str;
	}
	return NULL;
}

static size_t	ft_printf_printarg(va_list args, t_vars *vars)
{
	char *argstr;
	size_t arglen;

	// get strlen of the value we're converting
	argstr = ft_printf_getargstr(args, vars);
	if (vars->conversion == conv_c || vars->conversion == conv_percent)
		arglen = 1;
	else
		arglen = ft_strlen(argstr) + (vars->isnegsigned != 0);
	if (vars->width > arglen)
		vars->width -= arglen;
	else
		vars->width = 0;
	arglen += vars->width;
	if (vars->flag & flag_dash)
	{
		if (vars->isnegsigned)
			ft_putchar_fd('-', 1);
		// left justification, pad with ' 's
		if (vars->conversion == conv_c)
			ft_putchar_fd(*argstr, 1);
		else
			ft_putstr_fd(argstr, 1);
		while (vars->width > 0)
		{
			ft_putchar_fd(' ', 1);
			vars->width--;
		} 
	}
	else
	{
		// right justification
		if (vars->isnegsigned && vars->flag & flag_zero)
		{
			ft_putchar_fd('-', 1);
		}
		while (vars->width > 0)
		{
			if (vars->flag & flag_zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			vars->width--;
		}
		if (vars->conversion == conv_c)
			ft_putchar_fd(*argstr, 1);
		else
		{
			if (vars->isnegsigned && !(vars->flag & flag_zero))
				ft_putchar_fd('-', 1);
			ft_putstr_fd(argstr, 1);
		}
	}
	free(argstr);
	return arglen;
}
size_t	ft_printf(const char *s, ...)
{
	va_list args;
	t_vars	*vars;
	size_t len;
	char *str;

	str = (char*)s;
	len = 0;
	va_start (args, s);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			vars = vars_create(str, "-0.# +123456789", "cspdiuxX%");
			if (!vars)
				break ;
			len += ft_printf_printarg(args, vars);
			if (vars->endpoint)
				str = vars->endpoint;
			free(vars);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	va_end (args);
	return len;
}
