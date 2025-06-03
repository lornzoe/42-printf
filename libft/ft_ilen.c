/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:43:02 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 23:11:36 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ilen(int num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
