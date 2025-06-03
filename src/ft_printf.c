/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 18:53:13 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	process_conversion(char **str, va_list args)
{
	t_vars	*vars;
	size_t	len;

	(*str)++;
	if (**str == '\0')
		return (0);
	vars = ft_printf_vars_create(*str,
			FT_PRINTF_CHARS_FLAG, FT_PRINTF_CHARS_CONVERSION);
	if (!vars)
		return (0);
	len = ft_printf_printarg(args, vars);
	if (vars->endpoint)
		*str = vars->endpoint;
	free(vars);
	return (len);
}

size_t	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	len;
	char	*str;

	str = (char *)s;
	len = 0;
	va_start (args, s);
	while (*str != '\0')
	{
		if (*str == '%')
			len += process_conversion(&str, args);
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	va_end (args);
	return (len);
}
