#include <stdio.h>
#include <stdint.h> // for uintptr_t
#include "libft/libft.h"

char *ft_ptrtostr(void *ptr)
{
	size_t buffersize;
	uintptr_t ptrval;
	char *ptrstr;
	char *hex;

	if (ptr == NULL)
		return (ft_strdup("(nil)"));
	hex = "0123456789abcdef";
	ptrval = (uintptr_t)ptr;
	buffersize = 0;
	while (ptrval != 0)
	{
		ptrval /= 16;
		buffersize++;
	}
	ptrval = (uintptr_t)ptr;
	ptrstr = ft_calloc(buffersize + 1, sizeof(char));
	if (!ptrstr)
		return NULL;
	while (buffersize > 0)
	{
		ptrstr[buffersize-- - 1] = hex[ptrval % 16];
		ptrval /= 16;
	}
	return ptrstr;
}

int main(void)
{
	char *test = malloc(1);
	printf("%s\n", ft_ptrtostr(test));
	printf("%020p", test);
	return 0;
}	