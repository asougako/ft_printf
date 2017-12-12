#include "ft_printf.h"

int arg_o_hh(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned char i;
	char *print;

	i = (unsigned char)va_arg(arg, unsigned int);
	print = ft_itoabase(i, "01234567");
	preprocess_o(&specs);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_o_h(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned short i;
	char *print;

	i = (short)va_arg(arg, unsigned int);
	print = ft_itoabase(i, "01234567");
	preprocess_o(&specs);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_o_i(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned int i;
	char *print;

	i = (unsigned int)va_arg(arg, unsigned int);
	print = ft_itoabase(i, "01234567");
	preprocess_o(&specs);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_o_l(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned long i;
	char *print;

	i = (unsigned long)va_arg(arg, unsigned long);
	print = ft_itoabase(i, "01234567");
	preprocess_o(&specs);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_o_ll(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned long long i;
	char *print;

	i = (unsigned long long)va_arg(arg, unsigned long long);
	print = ft_itoabase(i, "01234567");
	preprocess_o(&specs);
	process_specs(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

