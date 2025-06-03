/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:24:33 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/21 17:22:41 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	itr;

	itr = 0;
	while (s1[itr] && s1[itr] == s2[itr] && itr < n)
		itr++;
	if (itr == n)
		return (0);
	return ((unsigned char)s1[itr] - (unsigned char)s2[itr]);
}
