/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:57:15 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 17:52:07 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getargstr_s(va_list args)
{
	char	*str;
	char	*temp;

	temp = va_arg(args, char *);
	if (temp == NULL)
	{
		str = ft_strdup("(null)");
	}
	else
	{
		str = ft_strdup(temp);
	}
	return (str);
}
