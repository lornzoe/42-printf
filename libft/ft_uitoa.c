/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:49:43 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 23:15:53 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	size_t	digits;
	char	*str;
	char	*itr;

	digits = ft_uilen_base(n, 10);
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	itr = str;
	if (n == 0)
		*itr = '0';
	while (n > 0)
	{
		*itr++ = n % 10 + '0';
		n /= 10;
	}
	return (ft_strrev(str, digits));
}
