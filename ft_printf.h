/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:26:30 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/31 21:50:31 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h> // for uintptr_t

#include "libft/libft.h"

enum e_flagtypes {
	flag_none		= 0b0000000,
	flag_dash		= 0b0000001,
	flag_zero		= 0b0000010,
	flag_precision	= 0b0000100,
	flag_pound		= 0b0001000,
	flag_space		= 0b0010000,
	flag_plus		= 0b0100000,
	flag_width		= 0b1000000
};

enum e_conversions{
	conv_c		= 'c', // char
	conv_s		= 's', // string
	conv_p		= 'p', // ptr address
	conv_d		= 'd', // decimal base10
	conv_i		= 'i', // int base 10 (same as d)
	conv_u		= 'u', // unsigned base 10
	conv_x		= 'x', // hexa lowercase
	conv_X 		= 'X', // hexa uppercase
	conv_percent = '%' // escape to render %
};

typedef struct s_vars {
	int	flag;
	size_t width;
	size_t precision;
	char conversion;
	char *endpoint;
	char isnegsigned;
} t_vars;

size_t	ft_printf(const char *str, ...);

#endif