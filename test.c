#include "ft_printf.h"
#include <stdio.h>

void	test(int64_t n)
{
	ft_print_memory(&n, 16);
}

int main(void)
{
	   printf("|%*s|\n", 8, "a");
	ft_printf("|%*s|\n", 8, "a");
	printf("\n");

	   printf("|%#*d|\n", 8, 42);
	ft_printf("|%#*d|\n", 8, 42);
	printf("\n");

	   printf("|%0*d|\n", 8, 42);
	ft_printf("|%0*d|\n", 8, 42);
	printf("\n");

	   printf("|%-*d|\n", 8, 42);
	ft_printf("|%-*d|\n", 8, 42);
	printf("\n");

	   printf("|%- *d|\n", 8, 42);
	ft_printf("|%- *d|\n", 8, 42);
	printf("\n");

	   printf("|%+*d|\n", 8, 42);
	ft_printf("|%+*d|\n", 8, 42);
	printf("\n");

	/*
	////
	printf("||%o||\n", 42);
	printf("||%#010.9o||\n", 4242);
	printf("\n");
	printf("\n");

	////
	printf("CHAR\n");
	   printf("char: %c\n", 'c');
	ft_printf("char: %c\n", 'c');

	printf("||%-10c||\n", 'c');

	printf("\n");
	printf("\n");
	////
	printf("STRING\n");
	   printf("%s>>>%s\n", "PONYS","SUCKS!");
	ft_printf("%s>>>%s\n", "PONYS","SUCKS!");

	printf("||%-.5s||\n", "0123456789");

	printf("||%#20.5s||\n", "0123456789");
	printf("||%020.5s||\n", "0123456789");
	printf("||% 20.5s||\n", "0123456789");
	printf("||%+20.5s||\n", "0123456789");
	printf("||%-20.5s||\n", "0123456789");

	printf("\n");
	printf("\n");
	////
	printf("SIGNED INT\n");

	char		*format = ft_strdup("signed test: %hhd, %hd, %d, %lld\n");
	char		arg_1 = 0x80;
	short		arg_2 = 0x8000;
	int			arg_4 = 0x80000000;
	long long	arg_8 = 0x8000000000000000;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	arg_1 = 0x7f;
	arg_2 = 0x7fff;
	arg_4 = 0x7fffffff;
	arg_8 = 0x7fffffffffffffff;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	printf("\n");
	printf("\n");
	////
	printf("UNSIGNED INT\n");

	format = ft_strdup("unsgined test: %+hhu, %+hu, %+u, %+llu\n");
	arg_1 = 0x80;
	arg_2 = 0x8000;
	arg_4 = 0x80000000;
	arg_8 = 0x8000000000000000;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	arg_1 = 0x7f;
	arg_2 = 0x7fff;
	arg_4 = 0x7fffffff;
	arg_8 = 0x7fffffffffffffff;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	printf("\n");
	printf("\n");
	////
	printf("OCTAL\n");

	format = ft_strdup("unsgined test: %+hho, %+ho, %+o, %+llo\n");
	arg_1 = 0x80;
	arg_2 = 0x8000;
	arg_4 = 0x80000000;
	arg_8 = 0x8000000000000000;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	arg_1 = 0x7f;
	arg_2 = 0x7fff;
	arg_4 = 0x7fffffff;
	arg_8 = 0x7fffffffffffffff;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	printf("\n");
	printf("\n");
	////
	printf("HEXADECIMAL\n");

	format = ft_strdup("unsgined test: %+hhx, %+hx, %+x, %+llx\n");
	arg_1 = 0x80;
	arg_2 = 0x8000;
	arg_4 = 0x80000000;
	arg_8 = 0x8000000000000000;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	arg_1 = 0x7f;
	arg_2 = 0x7fff;
	arg_4 = 0x7fffffff;
	arg_8 = 0x7fffffffffffffff;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	printf("\n");
	printf("\n");
	////
	printf("HEXADECIMAL\n");

	format = ft_strdup("unsgined test: %+hhX, %+hX, %+X, %+llX\n");
	arg_1 = 0x80;
	arg_2 = 0x8000;
	arg_4 = 0x80000000;
	arg_8 = 0x8000000000000000;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	arg_1 = 0x7f;
	arg_2 = 0x7fff;
	arg_4 = 0x7fffffff;
	arg_8 = 0x7fffffffffffffff;
	printf(format, arg_1, arg_2, arg_4, arg_8);
	ft_printf(format, arg_1, arg_2, arg_4, arg_8);

	printf("\n");
	printf("\n");
	*/
}