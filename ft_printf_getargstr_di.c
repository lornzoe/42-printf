/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_di.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:53:33 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 03:24:52 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char*	apply_precision_flag(char *str, t_vars *vars)
{
	char	*temp;

	temp = str;
	if (vars->flag & flag_has_precision && vars->precision > ft_strlen(temp))
	{
		str = ft_printf_getpaddedstr(vars->precision - ft_strlen(temp), temp, '0');
		free(temp);
	}
	return (str);
}

static char*	apply_sign_flag(char *str, t_vars *vars)
{
	char	*temp;

	if ((vars->flag & flag_plus || vars->flag & flag_space) && !vars->isnegsigned)
	{
		temp = str;
		if (vars->flag & flag_plus)
			str = ft_strjoin("+", temp);
		else
			str = ft_strjoin(" ", temp);
		free(temp);
	}
	return (str);
}

char	*ft_printf_getargstr_di(va_list args, t_vars *vars)
{
	char *str;
	char *temp;

	int x = va_arg(args, int);
	if (x == 0 && vars->flag & flag_has_precision && vars->precision == 0)
		return (ft_strdup(""));		
	if (x < 0)
	{
		vars->isnegsigned = 1;
		str = ft_itoa(ft_abs(x));
		if (*str == '-')
		{
			temp = str;
			str = ft_strtrim(str, "-");
			free(temp);
		}
	}
	else
		str = ft_itoa(x);
	str = apply_precision_flag(str, vars);
	if (!str)
		return (NULL);
	str = apply_sign_flag(str, vars);
	return (str);
}
