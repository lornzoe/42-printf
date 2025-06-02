/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:58:25 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 03:25:15 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getargstr_u(va_list args, t_vars *vars)
{
	char	*str;
	char	*temp;

	int x = va_arg(args, unsigned int);
	if (x == 0 && vars->flag & flag_has_precision && vars->precision == 0)
		return (ft_strdup(""));
	str = ft_uitoa(x);
	if (vars->flag & flag_has_precision && vars->precision > ft_strlen(str))
	{
		temp = str;
		str = ft_printf_getpaddedstr(vars->precision - ft_strlen(temp), temp, '0');
		free(temp);
	}
	return (str);
}
