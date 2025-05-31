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
	printf ("printf: %x\n", 100);
	ft_printf ("ft_printf: %x\n", 100);
	return 0;
}