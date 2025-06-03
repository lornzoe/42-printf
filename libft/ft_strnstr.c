/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:44:56 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:40:47 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*itr;
	size_t	littlelength;

	if (!little || ft_strlen((char *)little) == 0)
		return ((char *)big);
	if (!big || ft_strlen((char *)big) == 0)
		return (NULL);
	itr = (char *)big;
	littlelength = ft_strlen((char *)little);
	while (len >= littlelength)
	{
		if (!ft_strncmp(itr, (char *)little, littlelength))
			return (itr);
		itr++;
		len--;
	}
	return (NULL);
}
