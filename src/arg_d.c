#include "ft_printf.h"

int arg_d_hh(va_list arg, t_spec specs, int fd)
{
	int size;
	char i;
	char *print;

	i = (char)va_arg(arg, int);
	print = ft_itoa(i);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_d_h(va_list arg, t_spec specs, int fd)
{
	int size;
	short i;
	char *print;

	i = (short)va_arg(arg, int);
	print = ft_itoa(i);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_d_i(va_list arg, t_spec specs, int fd)
{
	int size;
	int i;
	char *print;

	i = va_arg(arg, int);
	print = ft_itoa(i);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_d_l(va_list arg, t_spec specs, int fd)
{
	int size;
	long i;
	char *print;

	i = va_arg(arg, long);
	print = ft_itoa(i);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_d_ll(va_list arg, t_spec specs, int fd)
{
	int size;
	long long i;
	char *print;

	i = va_arg(arg, long long);
	print = ft_itoa(i);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

