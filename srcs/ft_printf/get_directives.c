#include "ft_printf.h"
#include <stdio.h>

#define IS_ONE_TO_NINE(I) (ft_isdigit(I) && I != '0')
#define SUB_CHAR '$'
static void	get_flags(t_spec *specs, char *start, char *conv)
{
	char *a_flags;
	char *cmp;

	(*specs).flags = 0;
	a_flags = ft_strdup(ALLOWED_FLAGS);

	while (start < conv && !IS_ONE_TO_NINE(*start))
	{
		if ((cmp = ft_strchr(a_flags, *start)))
		{
			(*specs).flags |= 0x01ull << (cmp - a_flags);
			*start = SUB_CHAR;
		}
		start++;
	}
	ft_strdel(&a_flags);
}

static void	get_width(t_spec *specs, char *start, char *conv)
{
	char *end;
	char *width;

	(*specs).width = 0;
	(*specs).has_width= 0;
	while (start < conv)
	{
		if (ft_isdigit(*start))
		{
			(*specs).has_width= 1;
			break;
		}
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
	(*specs).width = ft_atoi(width);
	ft_strdel(&width);
	ft_memset(start, SUB_CHAR, end - start);
}

static void	get_prec(t_spec *specs, char *start, char *conv)
{
	char *end;
	char *width;

	(*specs).prec = 0;
	(*specs).has_prec = 0;
	if ((start = ft_strchr(start, '.')) == NULL)
		return;
	(*specs).has_prec = 1;
	start++;
	end = start;
	while (end < conv)
	{
		if (!ft_isdigit(*end))
			break;
		end++;
	}
	width = ft_strndup(start, end - start);
	(*specs).prec = ft_atoi(width);
	ft_strdel(&width);
	ft_memset(start, SUB_CHAR, end - start);
}

static void	get_lenght(t_spec *specs, char *start)
{
	char    *a_len[7] = {"hh", "h", "ll", "l", "z", "j", NULL};
	t_lenght len_tab[6] = {LENG_HH, LENG_H, LENG_LL, LENG_L, LENG_Z, LENG_J};
	int     index;

	index = 0;
	(*specs).lenght = LENG_I;
	while (*(a_len + index))
	{
		if (ft_strstr(start, *(a_len + index)))
		{
			(*specs).lenght = len_tab[index];
			return;
		}
		index++;
	}
}

t_spec get_directives(char *start, char *conv, va_list arg)
{
	t_spec  specs;
	char    *directives;
	int     dir_len;

	directives = ft_strndup(start, conv - start + 1);
	dir_len = ft_strlen(directives);

	//	printf("\n\tSTART: %s\n", directives);
	get_flags(&specs, directives, directives + dir_len);
	get_prec(&specs, directives, directives + dir_len);
	get_width(&specs, directives, directives + dir_len);
	if (ft_strchr(start, '*'))
	{
		specs.width = va_arg(arg, int);
		specs.has_width = 1;
	}
	get_lenght(&specs, directives);
	specs.conv = *conv;


	//  printf("\n\t  END: %s\n", directives);
//		printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n", specs.flags, specs.width, specs.prec, specs.lenght, specs.conv);
	ft_strdel(&directives);
	return(specs);
}
