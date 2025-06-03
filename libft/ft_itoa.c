/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:47:04 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/31 11:44:31 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		negative;
	int		digits;
	char	*str;
	char	*itr;
	long	num;

	negative = (n < 0);
	digits = ft_ilen(n) + negative;
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	itr = str;
	num = (long)n;
	if (negative)
		num = -num;
	if (num == 0)
		*itr = '0';
	while (num > 0)
	{
		*itr++ = (num % 10) + '0';
		num /= 10;
	}
	if (negative)
		*itr = '-';
	return (ft_strrev(str, digits));
}
