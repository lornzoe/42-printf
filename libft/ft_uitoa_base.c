/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:48:49 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 23:15:46 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	size_t	digits;
	size_t	baselen;
	char	*str;
	char	*itr;

	baselen = ft_strlen(base);
	digits = ft_uilen_base(n, baselen);
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	itr = str;
	if (n == 0)
		*itr = base[0];
	while (n > 0)
	{
		*itr++ = base[n % baselen];
		n /= baselen;
	}
	return (ft_strrev(str, digits));
}
