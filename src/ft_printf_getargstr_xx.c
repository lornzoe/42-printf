/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getargstr_xx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:00:58 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 18:53:09 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_precision_flag(char *str, t_vars *vars)
{
	char	*temp;
	size_t	diff;

	if (vars->flag & flag_has_precision && vars->precision > ft_strlen(str))
	{
		temp = str;
		diff = vars->precision - ft_strlen(temp);
		str = ft_printf_getpaddedstr(diff, temp, '0');
		free(temp);
	}
	return (str);
}

static char	*apply_hash_flag(char *str, unsigned int x, t_vars *vars)
{
	char	*temp;

	if (vars->flag & flag_hash && x != 0)
	{
		temp = str;
		if (vars->conversion == conv_x)
			str = ft_strjoin("0x", temp);
		else
			str = ft_strjoin("0X", temp);
		free(temp);
	}
	return (str);
}

char	*ft_printf_getargstr_xx(va_list args, t_vars *vars)
{
	char	*str;
	int		x;

	x = va_arg(args, unsigned int);
	if (x == 0 && vars->flag & flag_has_precision && vars->precision == 0)
		return (ft_strdup(""));
	if (vars->conversion == conv_x)
		str = ft_uitoa_base(x, "0123456789abcdef");
	else
		str = ft_uitoa_base(x, "0123456789ABCDEF");
	str = apply_precision_flag(str, vars);
	if (!str)
		return (NULL);
	str = apply_hash_flag(str, x, vars);
	return (str);
}
