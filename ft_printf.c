/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/21 21:51:58 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	vars_handlewidth(char *str, t_vars *vars)
{
			// get atoi of *str
			// overwrite var->width
			// get digits of the result of atoi
			// increment str by digits (leave 1 for the default ++)
}

int vars_handleprecision(char *str, t_vars *vars)
{
	vars->flag |= flag_period;
	// get atoi of *chr
	// overwrite var->precision
	// get digits of the result of atoi
	// increment str by digits
}

int vars_create(char *str, const char *set, const char *end, t_vars *vars)
{
	char *chr;
	char *str;
	while (ft_strchr(end, str) == NULL)
	{
		chr = ft_strchr(set, str);
		if (*chr == '-')
			vars->flag |= flag_dash;
		else if (ft_isnum(*chr) && *chr != '0')
		{
			// get atoi of *str
			// overwrite var->width
			// get digits of the result of atoi
			// increment str by digits (leave 1 for the default ++)
		}
		else if (*chr == '0')
			vars->flag |= flag_zero;
		else if (*chr == '.')
		{
			vars->flag |= flag_period;
			// get atoi of *chr
			// overwrite var->precision
			// get digits of the result of atoi
			// increment str by digits
		}
		else if (*chr == '#')
			vars->flag |= flag_pound;
		else if (*chr == ' ')
			vars->flag |= flag_space;
		else if (*chr == '+')
			vars->flag |= flag_plus;
		str++;
	}
	var->conversion = ft_strchr(end, str);
}

void	ft_printf(char *str, ...)
{
	va_list args;
	const char	*set = (const)ft_strdup("-0.# +123456789");
	const char	*end = (const)ft_strdup("cspdiuxX%");
	t_vars	*result;

	result = malloc(sizeof(t_vars));
	if (!result)
		return (NULL);
	
	va_start (args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			flags = 
			str++;
		}
		
	}
	va_end (args);
	free(set);
	free(end);
}

int main(void)
{
	ft_printf("hello %d %d %d %d", 69420, 123929, 23023029, 23092930);

	return 0;
}
