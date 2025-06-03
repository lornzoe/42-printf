/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:26:30 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 08:53:33 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>

# include "libft/libft.h"

# define FT_PRINTF_CHARS_FLAG "-0.# +123456789"
# define FT_PRINTF_CHARS_CONVERSION "cspdiuxX%"

enum e_flagtypes
{
	flag_none			= 0b0000000,
	flag_dash			= 0b0000001,
	flag_zero			= 0b0000010,
	flag_has_precision	= 0b0000100,
	flag_hash			= 0b0001000,
	flag_space			= 0b0010000,
	flag_plus			= 0b0100000,
	flag_has_width		= 0b1000000
};

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
	char	*endpoint;
	char	isnegsigned;
}	t_vars;

size_t	ft_printf(const char *str, ...);
t_vars	*ft_printf_vars_create(char *str, const char *set, const char *end);

char	*ft_printf_getargstr(va_list args, t_vars *vars);
char	*ft_printf_getargstr_c(va_list args);
char	*ft_printf_getargstr_s(va_list args, t_vars *vars);
char	*ft_printf_getargstr_p(va_list args, t_vars *vars);
char	*ft_printf_getargstr_di(va_list args, t_vars *vars);
char	*ft_printf_getargstr_u(va_list args, t_vars *vars);
char	*ft_printf_getargstr_xx(va_list args, t_vars *vars);

char	*ft_printf_getpaddedstr(size_t width, char *str, char pad);

size_t	ft_printf_printarg(va_list args, t_vars *vars);

#endif