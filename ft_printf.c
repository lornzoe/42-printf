/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:25:10 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/16 19:14:56 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	ft_printf(char *format, ...)
{
	// what lol
	// grab the variables 
	va_list arg;
	
	va_start (arg, format);
	vfprintf (stdout, format, arg);
	va_end (arg);

}

int main(void)
{
	ft_printf("hello %d %d %d %d", 69420, 123929, 23023029, 23092930);

	return 0;
}
