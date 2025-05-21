/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:26:30 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/21 21:50:35 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>

#include "libft/libft.h"

enum e_flagtypes {
	flag_none	= 0b000000,
	flag_dash	= 0b000001,
	flag_zero	= 0b000010,
	flag_period	= 0b000100,
	flag_pound	= 0b001000,
	flag_space	= 0b010000,
	flag_plus	= 0b100000
}

enum e_conversions{
	conv_nil	= NULL,
	conv_c		= 'c', // char
	conv_s		= 's', // string
	conv_p		= 'p', // ptr address
	conv_d		= 'd', // decimal base10
	conv_i		= 'i', // int base 10 (same as d)
	conv_u		= 'u', // unsigned base 10
	conv_x		= 'x', // hexa lowercase
	conv_X 		= 'X', // hexa uppercase
	conv_percent = '%' // escape to render %
}

typedef struct s_vars {
	int	flag;
	size_t width;
	size_t precision;
	char conversion;
} t_vars;

#endif