/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_s_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:57:15 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 18:00:36 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_printf_getargstr_s(va_list args, t_vars *vars)
{
	char	*str;
	char	*temp;

	temp = va_arg(args, char *);
	if (temp == NULL)
	{
		if (vars->flag & flag_has_precision && vars->precision < 6)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
	}
	else
	{
		if (vars->flag & flag_has_precision)
		{
			if (vars->precision > 0)
				str = ft_substr(temp, 0, vars->precision);
			else
				str = ft_strdup("");
		}
		else
			str = ft_strdup(temp);
	}
	return (str);
}
