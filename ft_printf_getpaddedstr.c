/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getpaddedstr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:45:50 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/02 22:47:28 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_printf_getpaddedstr(size_t width, char *str, char pad)
{
	char *temp;
	size_t i;
	char *result;
	if (width == 0)
		return (ft_strdup(str));
	temp = ft_calloc(width + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < width)
	{
		temp[i] = pad;
		i++;
	}
	result = ft_strjoin(temp, str);
	free(temp);
	return result;
}
