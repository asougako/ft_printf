#include "ft_printf.h"

int arg_xupp_hh(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned char i;
	char *print;

	i = (unsigned char)va_arg(arg, unsigned int);
	print = ft_itoabase(i, "0123456789ABCDEF");
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_xupp_h(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned short i;
	char *print;

	i = (short)va_arg(arg, unsigned int);
	print = ft_itoabase(i, "0123456789ABCDEF");
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_xupp_i(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned int i;
	char *print;

	i = (unsigned int)va_arg(arg, unsigned int);
	print = ft_itoabase(i, "0123456789ABCDEF");
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_xupp_l(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned long i;
	char *print;

	i = (unsigned long)va_arg(arg, unsigned long);
	print = ft_itoabase(i, "0123456789ABCDEF");
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_xupp_ll(va_list arg, t_spec specs, int fd)
{
	int size;
	unsigned long long i;
	char *print;

	i = (unsigned long long)va_arg(arg, unsigned long long);
	print = ft_itoabase(i, "0123456789ABCDEF");
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_xupp_z(va_list arg, t_spec specs, int fd)
{
	int		size;
	size_t	i;
	char	*print;

	i = (size_t)va_arg(arg, size_t);
	print = ft_itoabase(i, "0123456789ABCDEF");
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

int arg_xupp_j(va_list arg, t_spec specs, int fd)
{
	int			size;
	uintmax_t	i;
	char		*print;

	i = (uintmax_t)va_arg(arg, uintmax_t);
	print = ft_itoabase(i, "0123456789ABCDEF");
	process_specs_u(&print, specs);
	ft_putstr_fd(print, fd);
	size = ft_strlen(print);
	ft_strdel(&print);
	return(size);
}

