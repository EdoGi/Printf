
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	char	*op = NULL;
	int 	arg1 = 1613;
	char	*arg2 = "et petites ";
	char	arg3 = 'r';

	printf("\n\tMy Printf is : %d\n", ft_printf(op, arg1, arg2, arg3));
	printf("\n");
	printf("\n\tReal Printf is : %d\n", printf(op, arg1, arg2, arg3));
	return (0);
}