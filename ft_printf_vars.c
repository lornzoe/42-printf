/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:34:11 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 21:33:55 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void vars_handleconflictflags(t_vars *vars)
{
	if (vars->flag & flag_zero && vars->flag & flag_precision)
		vars->flag = vars->flag & ~(flag_zero);
	if (vars->flag & flag_zero && vars->conversion == conv_s)
		vars->flag = vars->flag & ~(flag_zero);

}

static int	vars_handleflag_width(char *str, t_vars *vars)
{
	size_t i;

	i = ft_atoi(str);
	if (i <= INT_MAX && i != 0)
	{
		vars->width = i;
		return ft_ilen(i);
	}
	return (0);
}

static int vars_handleflag_precision(char *str, t_vars *vars)
{
	size_t i;

	i = ft_atoi(str);
	if (i <= INT_MAX && i != 0)
	{
		vars->precision = i;
		return ft_ilen(i);
	}
	return (0);
}

static size_t vars_handleflags(char chr, char* str, t_vars *vars)
{
	if (chr == '-')
		vars->flag |= flag_dash;
	else if (ft_isdigit(chr) && chr != '0')
	{
		vars->flag |= flag_width;
		return (vars_handleflag_width(str, vars));
	}
	else if (chr == '0')
		vars->flag |= flag_zero;
	else if (chr == '.')
	{
		vars->flag |= flag_precision;
		str++;
		return (vars_handleflag_precision(str, vars) + 1);
	}
	else if (chr == '#')
		vars->flag |= flag_pound;
	else if (chr == ' ')
		vars->flag |= flag_space;
	else if (chr == '+')
		vars->flag |= flag_plus;
	return (1);
}

t_vars *vars_create(char *str, const char *set, const char *end)
{
	t_vars *vars;
	char *chr;

	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return NULL;
	while (ft_strchr(end, *str) == NULL)
	{
		chr = ft_strchr(set, *str);
		if (!chr)
			return NULL;
		str += vars_handleflags(*chr, str, vars);
	}
	vars->conversion = *(ft_strchr(end, *str));
	vars->endpoint = str;
	vars_handleconflictflags(vars);
	return (vars);
}
