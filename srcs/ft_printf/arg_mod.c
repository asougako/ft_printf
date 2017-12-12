#include "ft_printf.h"

int arg_mod(va_list arg, t_spec specs, int fd)
{
    (void)arg;
    (void)specs;
    ft_putchar_fd('%', fd);
    return(1);
}
