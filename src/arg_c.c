#include "ft_printf.h"

int arg_c_hh(va_list arg, t_spec specs)
{
	char c;

	c = (char)va_arg(arg, int);
	ft_putchar(c);
	return(1);
}

int arg_c_l(va_list arg, t_spec specs)
{
//	wchar_t *wc;
//
//	wc = va_arg(arg, wchar_t *);
//	ft_putchar(wc);
	return(1);
}
