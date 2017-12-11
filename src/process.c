#include "ft_printf.h"
#include <stdio.h>

int		index_tab[] = {
/*			0		1		2		3		4		5		6		7*/
/*04*/	/* */2,	/**/0,	/**/0,	/*#*/2,	/**/0,	/*%*/1,	/**/0,	/**/0,
/*05*/	/**/0,	/**/0,	/**/0,	/*+*/2,	/**/0,	/*-*/2,	/**/0,	/**/0,
/*06*/	/*0*/2,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*07*/	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*10*/	/**/0,	/**/0,	/**/0,	/*C*/1,	/*D*/1,	/**/0,	/**/0,	/**/0,
/*11*/	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/*O*/1,
/*12*/	/**/0,	/**/0,	/**/0,	/*S*/1,	/**/0,	/*U*/1,	/**/0,	/**/0,
/*13*/	/*X*/1,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,
/*14*/	/**/0,	/**/0,	/**/0,	/*c*/2,	/*d*/6,	/**/0,	/**/0,	/**/0,
/*15*/	/**/0,	/*i*/1,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/*o*/1,
/*16*/	/*p*/1,	/**/0,	/**/0,	/*s*/4,	/**/0,	/*u*/1,	/**/0,	/**/0,
/*17*/	/*x*/1,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0,	/**/0
};

char *process_specs(void *arg, t_spec specs)
{
	char *buff;
	int buff_size;

	buff_size = ft_strlen(arg) + specs.width + specs.prec + 3;
	buff = ft_strnew(buff_size);

	ft_strdel(&buff);
	return(arg);
}

int	arg_error(va_list arg, t_spec specs)
{
	return(0);
}

int	arg_percent(va_list arg, t_spec specs)
{
	ft_putchar('%');
	return(1);
}

int (*directives_table[])(va_list, t_spec) = {
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
	arg_d_l
};

#define IS_ONE_TO_NINE(I) (ft_isdigit(I) && I != '0')
int	get_flags(char *start, char *conv)
{
	int ret;
	char *a_flags;
	char *cmp;

	ret = 0;
	a_flags = ft_strdup(ALLOWED_FLAGS);

	while (start < conv && !IS_ONE_TO_NINE(*start))
	{
		if (cmp = ft_strchr(a_flags, *start))
		{
			ret |= 0x01ull << (cmp - a_flags);
			*start = '*';
		}
		start++;
	}
	ft_strdel(&a_flags);
	return(ret);
}

int	get_width(char *start, char *conv)
{
	char *end;
	char *width;
	int ret;

	while (start < conv)
	{
		if (ft_isdigit(*start))
			break;
		start++;
	}
	end = start;
	while (end < conv)
	{
		if (!ft_isdigit(*end))
			break;
		end++;
	}
	width = ft_strndup(start, end - start);
	ret = ft_atoi(width);
	ft_strdel(&width);
	ft_memset(start, '*', end - start);
	return(ret);
}

int	get_prec(char *start, char *conv)
{
	char *end;
	char *width;
	int ret;

	if ((start = ft_strchr(start, '.')) == NULL)
		return(-1);
	start++;
	end = start;
	while (end < conv)
	{
		if (!ft_isdigit(*end))
			break;
		end++;
	}
	width = ft_strndup(start, end - start);
	ret = ft_atoi(width);
	ft_strdel(&width);
	ft_memset(start, '*', end - start);
	return(ret);
}

int	get_lenght(char *start, char *end)
{
	char	*a_len[5] = {"hh", "h", "ll", "l", NULL};
	int		size_tab[4] = {LENG_HH, LENG_H, LENG_LL, LENG_L};
	int		index;
	int		ret;

	index = 0;
	ret = LENG_I;
	while (*(a_len + index))
	{
		if (ft_strstr(start, *(a_len + index)))
		{
			ret = size_tab[index];
			return(ret);
		}
		index++;
	}
	return(ret);
}

t_spec get_directives(char *start, char *conv)
{
	t_spec	specs;
	char	*directives;
	int		dir_len;

	directives = ft_strndup(start, conv - start + 1);
	dir_len = ft_strlen(directives);

	//	printf("\n\tSTART: %s\n", directives);
	specs.flags = get_flags(directives, directives + dir_len);
	specs.width = get_width(directives, directives + dir_len);
	specs.prec = get_prec(directives, directives + dir_len);
	specs.lenght = get_lenght(directives, directives + dir_len);
	specs.conv = *conv;
	//	printf("\n\t  END: %s\n", directives);
	//	printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n",\
	specs.flags, specs.width, specs.prec, specs.lenght, specs.conv);

	ft_strdel(&directives);
	return(specs);
}

int	process_directives(char *start, char *conv , va_list arg, int fd)
{
	int		len;
	int		jump_index;
	t_spec	specs;

	specs = get_directives(start, conv);

	if ((jump_index = index_tab[*conv - CONV_OFFSET]) < 0)
		jump_index = 0;
	printf("\nJUMPING TO %d + %d\n", jump_index, specs.lenght);
	(*directives_table[jump_index + specs.lenght])(arg, specs);


	len = 0;
	return(len);
}
