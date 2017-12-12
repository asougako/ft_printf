#include "ft_printf.h"

#define REMOVE_FLAG(F) ((*specs).flags &= ~F)
static void	preprocess(t_spec *specs, char *arg)
{
	REMOVE_FLAG(FLAG_PLUS);
	REMOVE_FLAG(FLAG_HASH);

	(void)arg;

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
	{
		buff = ft_strjoin("0", *arg);
	}
	else if (specs.flags & FLAG_HASH && specs.conv == 'x')
	{
		buff = ft_strjoin("0x", *arg);
	}
	else if (specs.flags & FLAG_HASH &&  specs.conv == 'X')
	{
		buff = ft_strjoin("0X", *arg);
	}
	else if (specs.flags & FLAG_SPACE && **arg != '-')
	{
		buff = ft_strjoin(" ", *arg);
	}
	else if (specs.flags & FLAG_PLUS && **arg != '-')
	{
		buff = ft_strjoin("+", *arg);
	}
	else
	{
		return;
	}
	ft_strdel(arg);
	*arg = buff;
}

static void	process_prec(char **arg, t_spec specs)
{
	char    *buff;
	char    filler;
	int     size;

	if (specs.has_prec == false)
		return;
	if (ft_strchr("sS", specs.conv))
	{
		filler = ' ';
		size = specs.prec;
	}
	else
	{
		filler = '0';
		size = ft_strlen(*arg);
		if (size < specs.prec)
			size = specs.prec;
	}
	buff = ft_strnew(size);
	ft_memset(buff, filler, size);
	if (size > (int)ft_strlen(*arg))
		ft_strncpy(buff + (size - ft_strlen(*arg)), *arg, size);
	else
		ft_strncpy(buff, *arg, size);
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
	if (specs.flags & FLAG_ZERO)
		filler = '0';
	else
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
}



void		process_specs_mod(char **arg, t_spec specs)
{
	//  printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n", specs.flags, specs.width, specs.pr    ec, specs.lenght, specs.conv);

	preprocess(&specs, *arg);

	//  printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n", specs.flags, specs.width, specs.pr    ec, specs.lenght, specs.conv);

	process_prec(arg, specs);
	process_flag(arg, specs);
	process_width(arg, specs);
}
