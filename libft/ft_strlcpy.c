/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:13:19 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/07 00:47:32 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	itr;

	if (size == 0)
		return (ft_strlen(src));
	itr = 0;
	while (itr < (size - 1) && src[itr] != '\0')
	{
		dst[itr] = src[itr];
		itr++;
	}
	dst[itr] = '\0';
	return (ft_strlen(src));
}
