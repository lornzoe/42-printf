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
