/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uilen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:45:58 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 23:16:19 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uilen_base(unsigned int num, int base)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= base;
		count++;
	}
	return (count);
}
