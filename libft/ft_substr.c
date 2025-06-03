/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:35:31 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:41:03 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*src;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		return (ft_calloc(1, sizeof(char)));
	l -= start;
	if (len < l)
		l = len;
	dest = ft_calloc(l + 1, sizeof(char));
	if (!dest)
		return (NULL);
	src = (char *)s;
	src += start;
	ft_strlcpy(dest, src, l + 1);
	return (dest);
}
