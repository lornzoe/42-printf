/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:16:08 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:52:16 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*last;

	ptr = (char *)s;
	last = NULL;
	while (*ptr)
	{
		if (*ptr == (char)c)
			last = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		last = ptr;
	return (last);
}
