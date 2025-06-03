/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_u_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:58:25 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 18:00:33 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_printf_getargstr_u(va_list args, t_vars *vars)
{
	char	*str;
	char	*temp;
	size_t	len;
	int		x;

	x = va_arg(args, unsigned int);
	if (x == 0 && vars->flag & flag_has_precision && vars->precision == 0)
		return (ft_strdup(""));
	str = ft_uitoa(x);
	len = ft_strlen(str);
	if (vars->flag & flag_has_precision && vars->precision > len)
	{
		temp = str;
		str = ft_printf_getpaddedstr(vars->precision - len, temp, '0');
		free(temp);
	}
	return (str);
}
