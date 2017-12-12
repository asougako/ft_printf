#include "ft_printf.h"

#define REMOVE_FLAG(F) ((*specs).flags &= ~F)
void	preprocess_c(t_spec *specs)
{
    REMOVE_FLAG(FLAG_PLUS);
}

void	preprocess_s(t_spec *specs)
{
    REMOVE_FLAG(FLAG_PLUS);
}

void	preprocess_d(t_spec *specs)
{
	(void)*specs;
}

void	preprocess_u(t_spec *specs)
{
    REMOVE_FLAG(FLAG_PLUS);
}

void	preprocess_o(t_spec *specs)
{
    REMOVE_FLAG(FLAG_PLUS);
}

void    preprocess_x(t_spec *specs)
{
    REMOVE_FLAG(FLAG_PLUS);
}

