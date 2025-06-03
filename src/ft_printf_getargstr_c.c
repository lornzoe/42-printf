/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:54:16 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 03:18:25 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getargstr_c(va_list args)
{
	char	*str;

	str = ft_calloc(1, 2);
	if (!str)
		return (NULL);
	*str = (char)va_arg(args, int);
	return (str);
}
