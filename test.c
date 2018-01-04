#include "ft_printf.h"
#include <stdio.h>

void	test(int64_t n)
{
	ft_print_memory(&n, 16);
}

int main(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	   printf("-->>%hhu<--\n", -1);
	ft_printf("-->>%hhu<--\n\n", -1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	   printf("-->>%hu<--\n", -1);
	ft_printf("-->>%hu<--\n\n", -1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	   printf("-->>%u<--\n", -1);
	ft_printf("-->>%u<--\n\n", -1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	   printf("-->>%lu<--\n", -1);
	ft_printf("-->>%lu<--\n\n", -1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	   printf("-->>%llu<--\n", -1);
	ft_printf("-->>%llu<--\n\n", -1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	   printf("-->>%zu<--\n", -1);
	ft_printf("-->>%zu<--\n\n", -1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	   printf("-->>%ju<--\n", -1);
	ft_printf("-->>%ju<--\n\n", -1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");




	   printf("-->>%#jx<--\n", 4294967296);
	ft_printf("-->>%#jx<--\n", 4294967296);
	   printf("-->>%#jx<--\n", -4294967296);
	ft_printf("-->>%#jx<--\n", -4294967296);
	   printf("|%20.3s|\n", "0123456789");
	ft_printf("|%20.3s|\n", "0123456789");
	printf("\n");

	printf("|%-20s|\n", "0123456789");
	ft_printf("|%-20s|\n", "0123456789");
	printf("\n");

	   printf("|%10.5d|\n", 42);
	ft_printf("|%10.5d|\n", 42);
	printf("\n");

	   printf("|%010.4d|\n", 42);
	ft_printf("|%010.4d|\n", 42);
	printf("\n");

	   printf("|%-10.4d|\n", 42);
	ft_printf("|%-10.4d|\n", 42);
	printf("\n");

	   printf("|%- 10.4d|\n", 42);
	ft_printf("|%- 10.4d|\n", 42);
	printf("\n");

	   printf("|%+10.4d|\n", 42);
	ft_printf("|%+10.4d|\n", 42);
	printf("\n");


	   printf("|%.20d|\n", 314159);
	ft_printf("|%.20d|\n", 314159);
	printf("\n");

	   printf("|%+#30.20x|\n", 314159);
	ft_printf("|%+#30.20x|\n", 314159);
	printf("\n");

	////
	   printf("||%o||\n", 42);
	ft_printf("||%o||\n", 42);
	   printf("||%#010.9o||\n", 4242);
	ft_printf("||%#010.9o||\n", 4242);
	printf("\n");
	printf("\n");

	////
	printf("CHAR\n");
	   printf("char: %c\n", 'c');
	ft_printf("char: %c\n", 'c');

	   printf("||%-10c||\n", 'c');
	ft_printf("||%-10c||\n", 'c');

	printf("\n");
	printf("\n");
	////
	printf("STRING\n");
	   printf("%s>>>%s\n", "PONYS","SUCKS!");
	ft_printf("%s>>>%s\n", "PONYS","SUCKS!");

	  printf("||%-.5s||\n", "0123456789");
	ft_printf("||%-.5s||\n", "0123456789");
 	   printf("||%#20.5s||\n", "0123456789");
	ft_printf("||%#20.5s||\n", "0123456789");

	   printf(" ||%-020.5s||\n", "0123456789");
	ft_printf(" ||%-020.5s||\n", "0123456789");


	   printf(" ||%30.20s||\n", "0123456789");
	ft_printf(" ||%30.20s||\n", "0123456789");
	   printf(" ||% 30.20s||\n", "0123456789");
	ft_printf(" ||% 30.20s||\n", "0123456789");
	   printf(" ||%+30.20s||\n", "0123456789");
	ft_printf(" ||%+30.20s||\n", "0123456789");
	   printf(" ||%-30.20s||\n", "0123456789");
	ft_printf(" ||%-30.20s||\n", "0123456789");
	   printf(" ||%#30.20s||\n", "0123456789");
	ft_printf(" ||%#30.20s||\n", "0123456789");
	   printf(" ||%030.20s||\n", "0123456789");
	ft_printf(" ||%030.20s||\n", "0123456789");
	printf("\n");
	   printf(" ||%15.20s||\n", "0123456789");
	ft_printf(" ||%15.20s||\n", "0123456789");
	   printf(" ||% 15.20s||\n", "0123456789");
	ft_printf(" ||% 15.20s||\n", "0123456789");
	   printf(" ||%+15.20s||\n", "0123456789");
	ft_printf(" ||%+15.20s||\n", "0123456789");
	   printf(" ||%-15.20s||\n", "0123456789");
	ft_printf(" ||%-15.20s||\n", "0123456789");
	   printf(" ||%#15.20s||\n", "0123456789");
	ft_printf(" ||%#15.20s||\n", "0123456789");
	   printf(" ||%015.20s||\n", "0123456789");
	ft_printf(" ||%015.20s||\n", "0123456789");
	printf("\n");
	   printf(" ||%-020.30s||\n", "0123456789");
	ft_printf(" ||%-020.30s||\n", "0123456789");
	   printf(" ||%020s||\n", "0123456789");
	ft_printf(" ||%020s||\n", "0123456789");

	/*
	   printf("||% 20.5s||\n", "0123456789");
	ft_printf("||% 20.5s||\n", "0123456789");
	   printf("||%+20.5s||\n", "0123456789");
	ft_printf("||%+20.5s||\n", "0123456789");
	   printf("||%-20.5s||\n", "0123456789");
	ft_printf("||%-20.5s||\n", "0123456789");

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
	ft_strdel(&format);
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
	ft_strdel(&format);
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
	ft_strdel(&format);
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
	ft_strdel(&format);
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
	ft_strdel(&format);
	*/
}
