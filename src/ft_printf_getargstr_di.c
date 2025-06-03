/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_di.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:53:33 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 17:38:36 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_printf_getargstr_di(va_list args, t_vars *vars)
{
	char	*str;
	char	*temp;
	int		x;

	x = va_arg(args, int);
	str = ft_itoa(ft_abs(x));
	if (x < 0)
	{
		vars->isnegsigned = 1;
		if (*str == '-')
		{
			temp = str;
			str = ft_strtrim(str, "-");
			free(temp);
		}
	}
	return (str);
}
