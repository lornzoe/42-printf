/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:28:51 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:40:33 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*temp;

	dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	temp = dest;
	while (*s)
	{
		*temp = *s;
		temp++;
		s++;
	}
	*temp = *s;
	return (dest);
}
