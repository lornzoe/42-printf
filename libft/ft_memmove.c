/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:04:18 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:37:23 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = (unsigned char *)src;
	if (d <= s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}
