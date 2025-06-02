#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// int v1 = printf(" %c %c %c \n", '0', 0, '1');
	// printf("!!!!\n");
	// int v2 = ft_printf(" %c %c %c \n", '0', 0, '1');
	// printf("%d, %d", v1, v2);
	//ft_printf(" %c %c %c \n", '0', 0, '1');

	// printf(" %c %c %c \n", '0', 0, '1');
	// printf("%s a\n", "WHAT IS WRONG WITH THIS STRING?");

	// ft_printf(" %c %c %c \n", '0', 0, '1');
	// ft_printf("%s a\n", "WHAT IS WRONG WITH THIS STRING?");

	//ft_printf("%s\n", NULL);
	// printf ("printf:\n %01d \n", -9);
	// ft_printf ("ft_printf:\n %01d \n", -9);

	ft_putstr_fd("------\n", 1);
	char *a = malloc(1);
	int x =  printf("pf:%#x\n", 0);
	int y =  ft_printf("ft:%#x\n", 0);
	printf("pf/ft: %d, %d", x, y);
	return 0;
}
