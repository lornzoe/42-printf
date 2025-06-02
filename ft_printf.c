/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 03:46:34 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			vars = ft_printf_vars_create(str, "-0.# +123456789", "cspdiuxX%");
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
