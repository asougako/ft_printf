#include "ft_printf.h"

int arg_u_hh(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned char i;
	char *print;

	i = (char)va_arg(arg, unsigned int);
	print = ft_uitoa(i);
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_h(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned short i;
	char *print;

	i = (short)va_arg(arg, unsigned int);
	print = ft_uitoa(i);
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_i(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned int i;
	char *print;

	i = va_arg(arg, unsigned int);
	print = ft_uitoa(i);
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_l(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned long i;
	char *print;

	i = va_arg(arg, unsigned long);
	print = ft_uitoa(i);
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_u_ll(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned long long i;
	char *print;

	i = va_arg(arg, unsigned long long);
	print = ft_uitoa(i);
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

