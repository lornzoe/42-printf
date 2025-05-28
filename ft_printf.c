/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/29 05:10:40 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_intlen(int num)
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
	// get atoi of *str
	str++;
	// overwrite var->width
	width = ft_atoi(str);
	vars->width = width;
	// get digits of the result of atoi
	// return increment
	if (width <= INT_MAX)
		return ft_intlen((int)width);
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
		return ft_intlen((int)width);
	return (0);
}

t_vars *vars_create(char *str, const char *set, const char *end)
{
	t_vars *vars;
	char *chr;
	char *str;

	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return NULL;
	// handle flags
	// this assumes we start after the %
	while (ft_strchr(end, str) == NULL)
	{
		chr = ft_strchr(set, str);
		if (*chr == '-')
			vars->flag |= flag_dash;
		else if (ft_isnum(*chr) && *chr != '0')
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
	vars->conversion = ft_strchr(end, str);
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
	ptrstr = ft_calloc(buffersize + 1, sizeof(char));
	if (!ptrstr)
		return NULL;
	while (buffersize > 0)
	{
		ptrstr[buffersize-- - 1] = hex[ptrval % 16];
		ptrval /= 16;
	}
	return ptrstr;
}

char *ft_printf_getargstr(va_list args, char conv)
{
	char *str;

	if (conv == conv_c)
	{
		str = ft_calloc(1, 2);
		if (!str)
			return NULL;
		*str = va_arg(args, char);
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
		str = ft_itoa(va_arg(args, unsigned int));
		return str;
	}
	if (conv == conv_x)
	{
		// we need a itoa_base func here
	}
	if (conv == conv_X)
	{
		// same here
	}
	if (conv == conv_percent)
	{
		str = ft_strdup("%");
		return str;
	}
}

void	ft_printf_renderarg(va_list args, t_vars *vars)
{
	// flags
	// - override 0
	// + overrides ' '

	char *argstr;
	size_t arglen;

	// get strlen of the value we're converting
	argstr = ft_printf_getargstr(args, vars->conversion);
	arglen = ft_strlen(argstr);
	if (vars->flag & flag_dash)
	{
		// left justification, pad with 0s
		ft_putstr_fd(argstr, 1);
		vars->width -= arglen;
		while (vars->width > 0)
		{
			ft_putchar_fd(' ', 1);
			vars->width--;
		} 
	}
	else
	{
		vars->width -= arglen;
		while (vars->width > 0)
		{
			if (vars->flag & flag_)
			ft_putchar_fd(' ', 1);
			vars->width--;
		}
		// right justification
	}
	free(argstr);
}

void	ft_printf(char *str, ...)
{
	va_list args;
	const char	*set = (const)ft_strdup("-0.# +123456789");
	const char	*end = (const)ft_strdup("cspdiuxX%");
	t_vars	*vars;

	va_start (args, str);
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
			
			// move the str to the new endpoint
			if (vars->endpoint)
				str = vars->endpoint;

		}
		str++;
	}
	va_end (args);
	free(set);
	free(end);
}

int main(void)
{
	ft_printf("hello %d %d %d %d", 69420, 123929, 23023029, 23092930);

	return 0;
}
