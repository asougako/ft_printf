
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

static	t_spec	pre_process(t_spec specs)
{
	if(specs.flags & FLAG_MINUS && specs.width > 0)
		specs.width = twos_complement(specs.width);

	//	Flag'#' has no effect with conv c, d, i, n, p, s, and u
	if (!(ft_strchr("oxX", specs.conv)))
		specs.flags |= ~FLAG_HASH;

	//	Prec remove flag '0'
	if (specs.prec >= 0)
		specs.flags |= ~FLAG_ZERO;

	//	Flag '-'remove flag '0'
	if (specs.flags & FLAG_MINUS)
		specs.flags |= ~FLAG_ZERO;

	//	Flag '+' remove flag ' '
	if (specs.flags & FLAG_PLUS)
		specs.flags |= ~FLAG_SPACE;

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
		ft_strjoin(*arg, " ");
	}
	else if	(specs.flags & FLAG_PLUS && **arg != '-')
	{
		ft_strjoin(*arg, "+");
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
	if (specs.has_prec== false)
		return;
}

void	process_width(char **arg, t_spec specs)
{
	if (specs.has_width == false)
		return;
}

void	process_specs(char **arg, t_spec specs)
{

//	printf("\n~~~%s\n", *arg);

	printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n",\
			specs.flags, specs.width, specs.prec, specs.lenght, specs.conv);
	specs = pre_process(specs);
	printf("f=%x\tw=%d\tp=%d\tl=%d\tc=%c\n",\
			specs.flags, specs.width, specs.prec, specs.lenght, specs.conv);

	//	process_flag(arg, specs);
	//	process_width(arg, specs);
	//	process_prec(arg, specs);
}

