/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printarg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:03:47 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 18:53:11 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_printarg_leftjustify(char *argstr, t_vars *vars)
{
	if (vars->isnegsigned)
		ft_putchar_fd('-', 1);
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

static void	ft_printf_printarg_rightjustify(char *argstr, t_vars *vars)
{
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

size_t	ft_printf_printarg(va_list args, t_vars *vars)
{
	char	*argstr;
	size_t	arglen;

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
		ft_printf_printarg_leftjustify(argstr, vars);
	else
		ft_printf_printarg_rightjustify(argstr, vars);
	free(argstr);
	return (arglen);
}
