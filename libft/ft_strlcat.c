/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:25:53 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/07 00:47:30 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	itr1;
	size_t	itr2;

	itr1 = ft_strlen(dst);
	if (size <= itr1)
		return (ft_strlen(src) + size);
	itr2 = 0;
	while ((itr1 + itr2) < (size - 1) && src[itr2] != 0)
	{
		dst[itr1 + itr2] = src[itr2];
		itr2++;
	}
	if (itr1 != size)
		dst[itr1 + itr2] = '\0';
	return (itr1 + ft_strlen(src));
}
