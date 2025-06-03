/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:12:33 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:34:21 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;
	size_t			totalsize;
	size_t			limit;

	limit = -1;
	if (!nmemb || !size)
		return (malloc(0));
	if (limit / nmemb < size)
		return (NULL);
	totalsize = nmemb * size;
	temp = malloc(totalsize);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < totalsize)
		temp[i++] = 0;
	return (temp);
}
