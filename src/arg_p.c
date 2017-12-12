#include "ft_printf.h"

int	arg_p(va_list arg, t_spec specs, int fd)
{
	specs.flags &= FLAG_HASH;
	return(arg_x_l(arg, specs, fd));
}
