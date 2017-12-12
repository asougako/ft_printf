/*
/TEXT/
	c	Character (int)
	C	Wide charactere (wint_t)
	s	Char string (char*)
	S	Wide char string (wchar_t*)
/INT/
	p:		pointer address
	d D i:	Signed decimal intteger
	u U:	Unsigned decimal integer
	o O:	Unsigned octal
	x X:	Unsigned hexadecimal
/FLOAT/
 */

#ifndef FT_PRINTF_H
#define  FT_PRINTF_H

/*
 *	INCLUDES
 */
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

/*
 *	DEFINES
 */
#define FLAG_HASH   (0x01 << 0)
#define FLAG_ZERO   (0x01 << 1)
#define FLAG_MINUS  (0x01 << 2)
#define FLAG_SPACE  (0x01 << 3)
#define FLAG_PLUS   (0x01 << 4)

#define LENG_I  0
#define LENG_HH 1
#define LENG_H  2
#define LENG_LL 3
#define LENG_L  4

#define ALLOWED_FLAGS "#0- +"
#define ALLOWED_SPECS "sSpdDioOuUxXcC%"

#define INDEX_TAB_LEN 96
#define DIRECTIVE_TAB_LEN 33

#define FLAG_OFFSET 0040
#define CONV_OFFSET 0040

/*
 *	TYPEDEF
 */
typedef enum	e_bool
{
	false,
	true = !false
}				t_bool;

typedef struct	s_spec{
	int	flags;
	t_bool	has_width;
	int	width;
	t_bool	has_prec;
	int	prec;
	int	lenght;
	int	conv;
}				t_spec;

/*
 *	GLOBALS
 */
int     index_tab[INDEX_TAB_LEN];
int		(*directives_table[DIRECTIVE_TAB_LEN])(va_list, t_spec, int);

/*
 *	PROTOTYPES
 */
int		ft_printf(char *format, ...);

int		process_directives(char *start, char *end, va_list arg, int fd);
t_spec	get_directives(char *start, char *conv,va_list arg);
void	process_specs(char **arg, t_spec specs);
void	pre_process_x(t_spec *specs);

int		arg_error(va_list arg, t_spec specs, int fd);
int		arg_percent(va_list arg, t_spec specs, int fd);
int		arg_c_hh(va_list arg, t_spec specs, int fd);
int		arg_c_l(va_list arg, t_spec specs, int fd);
int		arg_s_hh(va_list arg, t_spec specs, int fd);
int		arg_s_l(va_list arg, t_spec specs, int fd);
int		arg_d_hh(va_list arg, t_spec specs, int fd);
int		arg_d_h(va_list arg, t_spec specs, int fd);
int		arg_d_i(va_list arg, t_spec specs, int fd);
int		arg_d_l(va_list arg, t_spec specs, int fd);
int		arg_d_ll(va_list arg, t_spec specs, int fd);
int		arg_u_hh(va_list arg, t_spec specs, int fd);
int		arg_u_h(va_list arg, t_spec specs, int fd);
int		arg_u_i(va_list arg, t_spec specs, int fd);
int		arg_u_l(va_list arg, t_spec specs, int fd);
int		arg_u_ll(va_list arg, t_spec specs, int fd);
int		arg_o_hh(va_list arg, t_spec specs, int fd);
int		arg_o_h(va_list arg, t_spec specs, int fd);
int		arg_o_i(va_list arg, t_spec specs, int fd);
int		arg_o_l(va_list arg, t_spec specs, int fd);
int		arg_o_ll(va_list arg, t_spec specs, int fd);
int		arg_x_hh(va_list arg, t_spec specs, int fd);
int		arg_x_h(va_list arg, t_spec specs, int fd);
int		arg_x_i(va_list arg, t_spec specs, int fd);
int		arg_x_l(va_list arg, t_spec specs, int fd);
int		arg_x_ll(va_list arg, t_spec specs, int fd);
int		arg_xupp_hh(va_list arg, t_spec specs, int fd);
int		arg_xupp_h(va_list arg, t_spec specs, int fd);
int		arg_xupp_i(va_list arg, t_spec specs, int fd);
int		arg_xupp_l(va_list arg, t_spec specs, int fd);
int		arg_xupp_ll(va_list arg, t_spec specs, int fd);
int		arg_p(va_list arg, t_spec specs, int fd);
#endif
