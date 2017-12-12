
//  '#'     Alternate form
//      c, d, i, n, p, s, and u >> no effect
//      o       >>  FORCE 0
//      x, X    >>  Force 0x, 0X
//
//  '0'     Zero padding
//
//  '-'     Left justify
//
//  ' '     blank before positive
//
//  '+'     force sign
//
//
//  prec > '0'
//   '-' > '0'
//   '+' > ' '

#include "ft_printf.h"

#define REMOVE_FLAG(F) ((*specs).flags &= ~F)
void	pre_process_x(t_spec *specs)
{
	REMOVE_FLAG(FLAG_PLUS);
}

static	t_spec	pre_process(t_spec specs)
{

	if (specs.width < 0)
	{
		specs.flags &= FLAG_MINUS;
		specs.width = twos_complement(specs.width);
	}

	//	Flag'#' has no effect with conv c, d, i, n, p, s, and u
	if (!(ft_strchr("oxX", specs.conv)))
		specs.flags &= ~FLAG_HASH;

	//	Prec remove flag '0'
	if (specs.has_prec)
		specs.flags &= ~FLAG_ZERO;

	//	Flag '-'remove flag '0'
	if (specs.flags & FLAG_MINUS)
		specs.flags &= ~FLAG_ZERO;

	//	Flag '+' remove flag ' '
	if (specs.flags & FLAG_PLUS)
		specs.flags &= ~FLAG_SPACE;

	return(specs);
}




void	process_flag(char **arg, t_spec specs)
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
	else if	(specs.flags & FLAG_SPACE && **arg != '-')
	{
		buff = ft_strjoin(" ", *arg);
	}
	else if	(specs.flags & FLAG_PLUS && **arg != '-')
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

void	process_prec(char **arg, t_spec specs)
{
	char	*buff;
	char	filler;
	int		size;

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

void	process_width(char **arg, t_spec specs)
{
	char	*buff;
	char	filler;
	int		size;

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

void	process_specs(char **arg, t_spec specs)
{

//	printf("\n~~~%s\n", *arg);

//	printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n", specs.flags, specs.width, specs.prec, specs.lenght, specs.conv);
	specs = pre_process(specs);
//	printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n", specs.flags, specs.width, specs.prec, specs.lenght, specs.conv);

	process_prec(arg, specs);
	process_flag(arg, specs);
	process_width(arg, specs);
}

