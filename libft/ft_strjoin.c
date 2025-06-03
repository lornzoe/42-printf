/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:01:29 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/07 00:47:29 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*temp;
	char	*itr;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	itr = result;
	temp = (char *)s1;
	while (*temp)
		*itr++ = *temp++;
	temp = (char *)s2;
	while (*temp)
		*itr++ = *temp++;
	*itr = 0;
	return (result);
}
