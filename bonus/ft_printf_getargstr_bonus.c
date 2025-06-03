/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:19:01 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 18:00:45 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_printf_getargstr(va_list args, t_vars *vars)
{
	if (vars->conversion == conv_c)
		return (ft_printf_getargstr_c(args));
	if (vars->conversion == conv_s)
		return (ft_printf_getargstr_s(args, vars));
	if (vars->conversion == conv_p)
		return (ft_ptoa(va_arg(args, void *)));
	if (vars->conversion == conv_d || vars->conversion == conv_i)
		return (ft_printf_getargstr_di(args, vars));
	if (vars->conversion == conv_u)
		return (ft_printf_getargstr_u(args, vars));
	if (vars->conversion == conv_x || vars->conversion == conv_X)
		return (ft_printf_getargstr_xx(args, vars));
	if (vars->conversion == conv_percent)
		return (ft_strdup("%"));
	return (NULL);
}
