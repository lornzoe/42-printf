/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:15:38 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/16 16:18:03 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*newstr;
	size_t	x;

	i = 0;
	j = ft_strlen(s1);
	x = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && ft_isinset(set, s1[i]))
		i++;
	while (j > i && ft_isinset(set, s1[j - 1]))
		j--;
	newstr = ft_calloc(j - i + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < j)
		newstr[x++] = s1[i++];
	return (newstr);
}
