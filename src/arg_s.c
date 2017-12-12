#include "ft_printf.h"

int arg_s_hh(va_list arg, t_spec specs, int fd)
{
	char *str;

	str = ft_strdup(va_arg(arg, char *));
	process_specs(&str, specs);
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
	return(ft_strlen(str));
}

int arg_s_l(va_list arg, t_spec specs, int fd)
{
	(void)arg;
	(void)specs;
	(void)fd;

//	wchar_t *str;
//
//	str = va_arg(arg, wchar_t *);
//	ft_putstr_fd(str, fd);
//	return(ft_strlen(str));
	return(0);
}
