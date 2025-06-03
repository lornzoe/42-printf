/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:50:46 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:52:01 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*i;

	i = (char *)s;
	while (*i)
	{
		if (*i == (char)c)
			return (i);
		i++;
	}
	if (*i == (char)c)
		return (i);
	return (NULL);
}
