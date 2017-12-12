
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char		v1 = 0x80;
	short		v2 = 0x8000;
	int			v3 = 0x8000;
	long long	v4 = 0x8000;

	unsigned long long	l1 = (unsigned long long)v1;
	unsigned long long	l2 = (unsigned long long)v2;
	unsigned long long	l3 = (unsigned long long)v3;
	unsigned long long	l4 = (unsigned long long)v4;

	ft_print_memory(&v1, 8);
	ft_print_memory(&v2, 8);
	ft_print_memory(&v3, 8);
	ft_print_memory(&v4, 8);

	ft_print_memory(&l1, 8);
	ft_print_memory(&l2, 8);
	ft_print_memory(&l3, 8);
	ft_print_memory(&l4, 8);

	return(0);
}
