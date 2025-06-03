/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_xx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:00:58 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 17:39:59 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getargstr_xx(va_list args, t_vars *vars)
{
	char	*str;
	int		x;

	x = va_arg(args, unsigned int);
	if (vars->conversion == conv_x)
		str = ft_uitoa_base(x, "0123456789abcdef");
	else
		str = ft_uitoa_base(x, "0123456789ABCDEF");
	return (str);
}
