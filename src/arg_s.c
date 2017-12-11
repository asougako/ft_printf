#include "ft_printf.h"

int arg_s_hh(va_list arg, t_spec specs)
{
	char *str;

	str = va_arg(arg, char *);


	process_specs(&str, specs);

	ft_putstr(str);
	return(ft_strlen(str));
}

int arg_s_l(va_list arg, t_spec specs)
{
//	wchar_t *str;
//
//	str = va_arg(arg, wchar_t *);
//	ft_putstr(str);
//	return(ft_strlen(str));
	return(0);
}
