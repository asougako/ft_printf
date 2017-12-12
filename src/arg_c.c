#include "ft_printf.h"

int arg_c_hh(va_list arg, t_spec specs, int fd)
{
	char	c;
	char	*str;

	c = (char)va_arg(arg, int);
	str = ft_strnew(2);
	*str = c;
	process_specs(&str, specs);
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
	return(1);
}

int arg_c_l(va_list arg, t_spec specs, int fd)
{

	(void)arg;
	(void)specs;
	(void)fd;

//	wchar_t *wc;
//
//	wc = va_arg(arg, wchar_t *);
//	ft_putchar(wc);
	return(1);
}
