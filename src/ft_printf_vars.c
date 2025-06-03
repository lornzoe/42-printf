/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:34:11 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 17:52:45 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vars	*ft_printf_vars_create(char *str, const char *end)
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->conversion = *(ft_strchr(end, *str));
	return (vars);
}
