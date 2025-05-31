/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/31 22:25:18 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void vars_handleconflictflags(t_vars *vars)
{
	if (vars->flag & flag_zero && vars->flag & flag_precision)
		vars->flag = vars->flag & ~(flag_zero);
	if (vars->flag & flag_zero && vars->conversion == conv_s)
		vars->flag = vars->flag & ~(flag_zero);

}

void vars_printvars(t_vars *vars)
{
	printf(">>USING PRINTF(), REMEMBER TO REMOVE\n");
	printf(">>flag: %s\n", ft_uitoa_base((unsigned)vars->flag, "01"));
	printf(">>width: %zu\n", vars->width);
	printf(">>precision: %zu\n", vars->precision);
	printf(">>conversion: %c\n", vars->conversion);
	printf(">>isendsigned: %i\n", (int)vars->isnegsigned);
}

int	vars_handlewidth(char *str, t_vars *vars)
{
	size_t width;
	//str++;
	// get atoi of *str
	// overwrite var->width
	width = ft_atoi(str);
	vars->width = width;
	// get digits of the result of atoi
	// return increment
	if (width <= INT_MAX)
		return ft_ilen(width) - 1;
	return (0);
}

int vars_handleprecision(char *str, t_vars *vars)
{
	size_t width;
	// get atoi of *chr
	str++;
	width = ft_atoi(str);
	// overwrite var->precision
	vars->precision = width;
	// get digits of the result of atoi
	// increment str by digits
	if (width <= INT_MAX)
		return ft_ilen(width);
	return (0);
}

t_vars *vars_create(char *str, const char *set, const char *end)
{
	t_vars *vars;
	char *chr;

	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return NULL;
	// initialise
	vars->width = 0;
	vars->precision = 0;
	vars->isnegsigned = 0;

	// handle flags
	// this assumes we start after the %
	while (ft_strchr(end, *str) == NULL)
	{
		chr = ft_strchr(set, *str);
		ft_putchar_fd(*chr, 1);
		if (*chr == '-')
			vars->flag |= flag_dash;
		else if (ft_isdigit(*chr) && *chr != '0')
		{
			// ft_putstr_fd("> width triggered\n", 1);
			str += vars_handlewidth(str, vars);
			vars->flag |= flag_width;
		}
		else if (*chr == '0')
			vars->flag |= flag_zero;
		else if (*chr == '.')
		{
			// ft_putstr_fd("> precision triggered\n", 1);
			str += vars_handleprecision(str, vars);
			vars->flag |= flag_precision;
		}
		else if (*chr == '#')
			vars->flag |= flag_pound;
		else if (*chr == ' ')
			vars->flag |= flag_space;
		else if (*chr == '+')
			vars->flag |= flag_plus;
		str++;
	}
	// handle conversion
	vars->conversion = *(ft_strchr(end, *str));
	vars->endpoint = str;
	return vars;
}

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
	// create a temp string with x 0s
	temp = ft_calloc(zeros + 1, sizeof(char));
	if (!temp)
		return NULL;
	i = 0;
	while (i < zeros)
		temp[i++] = '0';
	// strjoin with current string
	result = ft_strjoin(temp, str);
	free(temp);
	return result;
}

char *ft_printf_getargstr(va_list args, t_vars *vars)
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
		ft_putstr_fd("ok!\n", 1);
		char *temp;
		temp = va_arg(args, char*);
		if (temp == NULL)
			str = ft_strdup("");
		else if (*temp == '\0')
			str = ft_strdup("");
		else
		{
			if (vars->flag & flag_precision)
			{
				if (vars->precision)
					str = ft_substr(temp, 0, vars->precision);
				else
					str = ft_strdup("");
			}
			else
				str = ft_strdup(temp);
		}
		free(temp);
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
	if (conv == conv_x)
	{
		str = ft_uitoa_base(va_arg(args, unsigned int), "0123456789abcdef");
		return ft_strrev(str, ft_strlen(str));
	}
	if (conv == conv_X)
	{
		// same here
		str = ft_uitoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		return ft_strrev(str, ft_strlen(str));
	}
	if (conv == conv_percent)
	{
		str = ft_strdup("%");
		return str;
	}
	return NULL;
}

size_t	ft_printf_renderarg(va_list args, t_vars *vars)
{
	// flags
	// - override 0
	// + overrides ' '

	char *argstr;
	size_t arglen;

	// vars_printvars(vars);
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
	const char	*set = "-0.# +123456789";
	const char	*end = "cspdiuxX%";
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
				break;
			// create the vars
			vars = vars_create(str, set, end);
			if (!vars)
				return 0;
			// process the vars
			vars_handleconflictflags(vars);
			len += ft_printf_renderarg(args, vars);
			// move the str to the new endpoint
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
