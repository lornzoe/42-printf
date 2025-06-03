/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:34:30 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:36:49 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;

	if (n == 0)
		return (0);
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*one - *two != 0)
			return (*one - *two);
		one++;
		two++;
	}
	return (0);
}
