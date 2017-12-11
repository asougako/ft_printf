#include "ft_printf.h"

int arg_u_hh(va_list arg, t_spec specs)
{
	int size;
	unsigned char i;
	char *print;

	i = (char)va_arg(arg, unsigned int);
	print = ft_uitoa(i);
	ft_putstr(print);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_h(va_list arg, t_spec specs)
{
	int size;
	unsigned short i;
	char *print;

	i = (short)va_arg(arg, unsigned int);
	print = ft_uitoa(i);
	ft_putstr(print);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_i(va_list arg, t_spec specs)
{
	int size;
	unsigned int i;
	char *print;

	i = va_arg(arg, unsigned int);
	print = ft_uitoa(i);
	ft_putstr(print);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_l(va_list arg, t_spec specs)
{
	int size;
	unsigned long i;
	char *print;

	i = va_arg(arg, unsigned long);
	print = ft_uitoa(i);
	ft_putstr(print);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_ll(va_list arg, t_spec specs)
{
	int size;
	unsigned long long i;
	char *print;

	i = va_arg(arg, unsigned long long);
	print = ft_uitoa(i);
	ft_putstr(print);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}
