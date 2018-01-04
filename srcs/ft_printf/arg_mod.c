#include "ft_printf.h"

int arg_mod(va_list arg, t_spec specs, int fd)
{
	char	*str;

    (void)arg;
    (void)specs;
	str = ft_strdup("%");
	process_specs_mod(&str, specs);
    ft_putstr_fd(str, fd);
	ft_strdel(&str);
    return(ft_strlen(str));
}
