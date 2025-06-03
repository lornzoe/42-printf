/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:58:25 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 17:54:03 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getargstr_u(va_list args)
{
	char	*str;
	int		x;

	x = va_arg(args, unsigned int);
	str = ft_uitoa(x);
	return (str);
}
