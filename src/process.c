#include "ft_printf.h"
#include <stdio.h>

//	jump index table
int		index_tab[INDEX_TAB_LEN] = {
/*			0		1		2		3		4		5		6		7*/
/*04*/	/* */2,	/**/0,	/**/0,	/*#*/2,	/**/0,	/*%*/1,	/**/0,	/**/0,
/*05*/	/**/0,	/**/0,	/**/0,	/*+*/2,	/**/0,	/*-*/2,	/**/0,	/**/0,
/*06*/	/*0*/2,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*07*/	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*10*/	/**/0,	/**/0,	/**/0,	/*C*/1,	/*D*/10,/**/0,	/**/0,	/**/0,
/*11*/	/**/0,	/*I*/10,/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/*O*/20,
/*12*/	/**/0,	/**/0,	/**/0,	/*S*/1,	/**/0,	/*U*/15,/**/0,	/**/0,
/*13*/	/*X*/26,/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*14*/	/**/0,	/**/0,	/**/0,	/*c*/2,	/*d*/6,	/**/0,	/**/0,	/**/0,
/*15*/	/**/0,	/*i*/6,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/*o*/16,
/*16*/	/*p*/1,	/**/0,	/**/0,	/*s*/4,	/**/0,	/*u*/11,/**/0,	/**/0,
/*17*/	/*x*/21,/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0
};

//char *process_specs(void *arg, t_spec specs)
//{
//	char *buff;
//	int buff_size;
//
//	buff_size = ft_strlen(arg) + specs.width + specs.prec + 3;
//	buff = ft_strnew(buff_size);
//
//	ft_strdel(&buff);
//	return(arg);
//}

int	arg_error(va_list arg, t_spec specs, int fd)
{
	(void)arg;
	(void)specs;
	(void)fd;
	return(0);
}

int	arg_percent(va_list arg, t_spec specs, int fd)
{
	(void)arg;
	(void)specs;
	ft_putchar_fd('%', fd);
	return(1);
}

//conv func jump table
int (*directives_table[DIRECTIVE_TAB_LEN])(va_list, t_spec, int) = {
	arg_error,		//	0
	arg_percent,	//	1
	arg_c_hh,		//	2
	arg_c_l,
	arg_s_hh,		//	4
	arg_s_l,
	arg_d_i,		//	6
	arg_d_hh,
	arg_d_h,
	arg_d_ll,
	arg_d_l,
	arg_u_i,		//	11
	arg_u_hh,
	arg_u_h,
	arg_u_ll,
	arg_u_l,
	arg_o_i,		//	16
	arg_o_hh,
	arg_o_h,
	arg_o_ll,
	arg_o_l,
	arg_x_i,		//	21
	arg_x_hh,
	arg_x_h,
	arg_x_ll,
	arg_x_l,
	arg_xupp_i,		//	26
	arg_xupp_hh,
	arg_xupp_h,
	arg_xupp_ll,
	arg_xupp_l,
	arg_p
};

int	process_directives(char *start, char *conv , va_list arg, int fd)
{
	int		len;
	int		jump_index;
	t_spec	specs;

	specs = get_directives(start, conv, arg);

	if ((jump_index = index_tab[*conv - CONV_OFFSET]) < 0)
		jump_index = 0;
//	printf("\nJUMPING TO %d + %d (%p)\n", jump_index, specs.lenght, directives_table[jump_index + specs.lenght]);
	(*directives_table[jump_index + specs.lenght])(arg, specs, fd);


	len = 0;
	return(len);
}
