/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:26:30 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 17:53:56 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>

# include "../libft/libft.h"

# define FT_PRINTF_CHARS_CONVERSION "cspdiuxX%"

enum e_conversions
{
	conv_none		= 0,
	conv_c			= 'c',
	conv_s			= 's',
	conv_p			= 'p',
	conv_d			= 'd',
	conv_i			= 'i',
	conv_u			= 'u',
	conv_x			= 'x',
	conv_X			= 'X',
	conv_percent	= '%'
};

typedef struct s_vars
{
	int		flag;
	size_t	width;
	size_t	precision;
	char	conversion;
	char	isnegsigned;
}	t_vars;

size_t	ft_printf(const char *str, ...);
t_vars	*ft_printf_vars_create(char *str, const char *end);

char	*ft_printf_getargstr(va_list args, t_vars *vars);
char	*ft_printf_getargstr_c(va_list args);
char	*ft_printf_getargstr_s(va_list args);
char	*ft_printf_getargstr_p(va_list args, t_vars *vars);
char	*ft_printf_getargstr_di(va_list args, t_vars *vars);
char	*ft_printf_getargstr_u(va_list args);
char	*ft_printf_getargstr_xx(va_list args, t_vars *vars);

size_t	ft_printf_printarg(va_list args, t_vars *vars);

#endif