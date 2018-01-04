#include "ft_printf.h"
#include <stdio.h>

//	Jump index table
int		index_tab[INDEX_TAB_LEN] = {
/*			0		1		2		3		4		5		6		7*/
/*04*/	/* */2,	/**/0,	/**/0,	/*#*/2,	/**/0,	/*%*/1,	/**/0,	/**/0,
/*05*/	/**/0,	/**/0,	/**/0,	/*+*/2,	/**/0,	/*-*/2,	/**/0,	/**/0,
/*06*/	/*0*/2,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*07*/	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*10*/	/**/0,	/**/0,	/**/0,	/*C*/1,	/*D*/10,/**/0,	/**/0,	/**/0,
/*11*/	/**/0,	/*I*/10,/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/*O*/24,
/*12*/	/**/0,	/**/0,	/**/0,	/*S*/1,	/**/0,	/*U*/17,/**/0,	/**/0,
/*13*/	/*X*/34,/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*14*/	/**/0,	/**/0,	/**/0,	/*c*/2,	/*d*/6,	/**/0,	/**/0,	/**/0,
/*15*/	/**/0,	/*i*/6,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/*o*/20,
/*16*/	/*p*/1,	/**/0,	/**/0,	/*s*/4,	/**/0,	/*u*/13,/**/0,	/**/0,
/*17*/	/*x*/27,/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0
};

//	Conv func jump table
int (*directives_table[DIRECTIVE_TAB_LEN])(va_list, t_spec, int) = {
	arg_err,		//	0
	arg_mod,		//	1
	arg_c_hh,		//	2
	arg_c_l,
	arg_s_hh,		//	4
	arg_s_l,
	arg_d_i,		//	6
	arg_d_hh,
	arg_d_h,
	arg_d_ll,
	arg_d_l,
	arg_d_z,
	arg_d_j,
	arg_u_i,		//	13
	arg_u_hh,
	arg_u_h,
	arg_u_ll,
	arg_u_l,
	arg_u_z,
	arg_u_j,
	arg_o_i,		//	20
	arg_o_hh,
	arg_o_h,
	arg_o_ll,
	arg_o_l,
	arg_o_z,
	arg_o_j,
	arg_x_i,		//	27
	arg_x_hh,
	arg_x_h,
	arg_x_ll,
	arg_x_l,
	arg_x_z,
	arg_x_j,
	arg_xupp_i,		//	34
	arg_xupp_hh,
	arg_xupp_h,
	arg_xupp_ll,
	arg_xupp_l,
	arg_xupp_z,
	arg_xupp_j,
	arg_p			//	41
};

int	process_directives(char *start, char *conv , va_list arg, int fd)
{
	int		len;
	int		jump_index;
	t_spec	specs;

	len = 0;
	specs = get_directives(start, conv, arg);

	if ((jump_index = index_tab[*conv - CONV_OFFSET]) < 0)
		jump_index = 0;

//	printf("\nJUMPING TO %d + %d (%p)\n", jump_index, specs.lenght, directives_table[jump_index + specs.lenght]);

	len = (*directives_table[jump_index + specs.lenght])(arg, specs, fd);
	return(len);
}
