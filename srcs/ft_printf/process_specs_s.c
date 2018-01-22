/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specs_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:06:33 by asougako          #+#    #+#             */
/*   Updated: 2018/01/05 12:12:49 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define REMOVE_FLAG(F) ((*specs).flags &= ~F)
static void	preprocess(t_spec *specs, char *arg)
{
	(void)arg;
	REMOVE_FLAG(FLAG_PLUS);
	REMOVE_FLAG(FLAG_HASH);
	REMOVE_FLAG(FLAG_SPACE);
	if ((*specs).width < 0)
	{
		(*specs).flags &= FLAG_MINUS;
		(*specs).width = twos_complement((*specs).width);
	}
	//  Prec remove flag '0'
	if ((*specs).prec)
		REMOVE_FLAG(FLAG_ZERO);
	//  Flag '-'remove flag '0'
	if ((*specs).flags & FLAG_MINUS)
		REMOVE_FLAG(FLAG_ZERO);
	//  Flag '+' remove flag ' '
	if ((*specs).flags & FLAG_PLUS)
		REMOVE_FLAG(FLAG_SPACE);
}

static void	process_flag(char **arg, t_spec specs)
{
	char *buff;

	//HASH
	if ((specs.flags & FLAG_HASH) && (specs.conv == 'o'))
		buff = ft_strjoin("0", *arg);
	else if (specs.flags & FLAG_HASH && specs.conv == 'x')
		buff = ft_strjoin("0x", *arg);
	else if (specs.flags & FLAG_HASH &&  specs.conv == 'X')
		buff = ft_strjoin("0X", *arg);
	else if (specs.flags & FLAG_SPACE && **arg != '-')
		buff = ft_strjoin(" ", *arg);
	else if (specs.flags & FLAG_PLUS && **arg != '-')
		buff = ft_strjoin("+", *arg);
	else
		return;
	ft_strdel(arg);
	*arg = buff;
}

static void	process_prec(char **arg, t_spec specs)
{
	char    *buff;
	int     size;

	size = specs.prec;
	if (specs.has_prec == false)
		return;
	if (size > (int)ft_strlen(*arg))
		return;
	buff = ft_strndup(*arg, size);
	ft_strdel(arg);
	*arg = buff;
}

static void	process_width(char **arg, t_spec specs)
{
	char    *buff;
	char    filler;
	int     size;

	if (specs.has_width == false)
		return;
	filler = ' ';
	size = ft_strlen(*arg);
	if (size < specs.width)
		size = specs.width;
	buff = ft_strnew(size);
	ft_memset(buff, filler, size);
	if (specs.flags & FLAG_MINUS)
		ft_strncpy(buff, *arg, ft_strlen(*arg));
	else
		ft_strncpy(buff + (size - ft_strlen(*arg)), *arg, ft_strlen(*arg));
	ft_strdel(arg);
	*arg = buff;

	printf("HAS WIDTH\n");
	printf("HAS WIDTH\n");
	printf("FILLER = %c\n", filler);
}



void		process_specs_s(char **arg, t_spec specs)
{
	(void)arg;
	(void)specs;


	//  printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n", specs.flags, specs.width, specs.pr    ec, specs.lenght, specs.conv);

	preprocess(&specs, *arg);

	//  printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n", specs.flags, specs.width, specs.pr    ec, specs.lenght, specs.conv);

	process_prec(arg, specs);
	process_flag(arg, specs);
//	process_width(arg, specs);
}
