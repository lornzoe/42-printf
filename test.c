/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:29:37 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/03 08:29:38 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_putstr_fd("------\n", 1);
	char *a = malloc(1);
	int x =  printf("pf:%#x\n", 0);
	int y =  ft_printf("ft:%#x\n", 0);
	printf("pf/ft: %d, %d", x, y);
	return (0);
}
