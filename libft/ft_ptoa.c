/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:37:47 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 23:17:03 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_hex_len(uintptr_t num, size_t base)
{
	size_t	digits;

	digits = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= base;
		digits++;
	}
	return (digits);
}

char	*ft_ptoa(void *ptr)
{
	size_t		buffersize;
	uintptr_t	ptrval;
	char		*ptrstr;
	char		*hex;

	if (ptr == NULL)
		return (ft_strdup("(nil)"));
	hex = "0123456789abcdef";
	ptrval = (uintptr_t)ptr;
	buffersize = get_hex_len(ptrval, 16);
	ptrstr = ft_calloc(buffersize + 3, sizeof(char));
	if (!ptrstr)
		return (NULL);
	ptrstr[0] = '0';
	ptrstr[1] = 'x';
	while (buffersize > 0)
	{
		ptrstr[buffersize-- + 1] = hex[ptrval % 16];
		ptrval /= 16;
	}
	return (ptrstr);
}
