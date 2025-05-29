/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/29 21:52:47 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strrev(char *str, size_t len)
{
	size_t	start;
	size_t	end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

size_t ft_uilen_base(unsigned int num, int base)
{
	size_t count;

	count = 0;
	if (num == 0)
		return 1;
	while (num != 0)
	{
		num /= base;
		count++;
	}
	return count;
}

char *ft_uitoa_base(unsigned int n, char *base)
{
	size_t digits;
	size_t baselen;
	char	*str;
	char	*itr;

	baselen = ft_strlen(base);
	digits = ft_uilen_base(n, baselen);
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return NULL;
	itr = str;
	if (n == 0)
		*itr = base[0];
	while (n > 0)
	{
		*itr++ = base[n % baselen];
		n /= baselen;
	}
	return str;
}

char *ft_uitoa(unsigned int n)
{
	size_t digits;
	char	*str;
	char	*itr;

	digits = ft_uilen_base(n, 10);
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return NULL;
	itr = str;
	if (n == 0)
		*itr = '0';
	while (n > 0)
	{
		*itr++ = n % 10 + '0';
		n /= 10;
	}
	return ft_strrev(str, digits);
}

size_t ft_ilen(int num)
{
	size_t count;

	count = 0;
	if (num == 0)
		return 1;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return count;
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
	if (width <= INT_MAX && width >= 0)
		return ft_ilen(width) - 1;
	return (0);
}

int vars_handleprecision(char *str, t_vars *vars)
{
	size_t width;
	// get atoi of *chr
	width = ft_atoi(str);
	// overwrite var->precision
	vars->precision = width;
	// get digits of the result of atoi
	// increment str by digits
	if (width <= INT_MAX)
		return ft_ilen((int)width) - 1;
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

	// handle flags
	// this assumes we start after the %
	while (ft_strchr(end, *str) == NULL)
	{
		chr = ft_strchr(set, *str);
		if (*chr == '-')
			vars->flag |= flag_dash;
		else if (ft_isdigit(*chr) && *chr != '0')
		{
			str += vars_handlewidth(str, vars);
		}
		else if (*chr == '0')
			vars->flag |= flag_zero;
		else if (*chr == '.')
		{
			vars->flag |= flag_period;
			// get atoi of *chr
			// overwrite var->precision
			// get digits of the result of atoi
			// increment str by digits
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
		str = va_arg(args, char*);
		str = ft_strdup(str);
		return str;
	}
	if (conv == conv_p)
	{
		return ft_ptrtostr(va_arg(args, void*));
	}
	if (conv == conv_d || conv == conv_i)
	{
		str = ft_itoa(va_arg(args, int));
		return str;
	}
	if (conv == conv_u)
	{
		str = ft_uitoa(va_arg(args, unsigned int));
		return str;
	}
	if (conv == conv_x)
	{
		str = ft_uitoa_base(va_arg(args, unsigned int), "0123456789abcdef");
		return str;
	}
	if (conv == conv_X)
	{
		// same here
		str = ft_uitoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		return str;
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

	// get strlen of the value we're converting
	argstr = ft_printf_getargstr(args, vars);
	if (vars->conversion == conv_c || vars->conversion == conv_percent)
		arglen = 1;
	else
		arglen = ft_strlen(argstr);
	if (vars->width > arglen)
		vars->width -= arglen;
	else
		vars->width = 0;
	arglen += vars->width;
	if (vars->flag & flag_dash)
	{
		// left justification, pad with 0s
		if (vars->conversion == conv_c)
			ft_putchar_fd(*argstr, 1);
		else
			ft_putstr_fd(argstr, 1);
		while (vars->width > 0)
		{
			ft_putchar_fd('l', 1);
			vars->width--;
		} 
	}
	else
	{
		// right justification

		while (vars->width > 0)
		{
			if (vars->flag & flag_zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd('r', 1);
			vars->width--;
		}
		if (vars->conversion == conv_c)
			ft_putchar_fd(*argstr, 1);
		else
			ft_putstr_fd(argstr, 1);
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
			{
				// handle error
			}
			// process the vars with the va_list
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

// int main(void)
// {
// 	ft_printf("hello %010d %c\n", 69, 'A');
// 	printf("----\n");
// 	printf("hello %010d %c\n", 69, 'A');
// 	printf("%#x", -1);
// 	printf("!!!!\n");
// 	return 0;
// }
