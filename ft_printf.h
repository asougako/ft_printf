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
 **	INCLUDES
 */
#include <libft/libft.h>
#include <stdarg.h>

/*
 **	DEFINES
 */
#define FLAG_HASH   0x01 << 0
#define FLAG_ZERO   0x01 << 1
#define FLAG_MINUS  0x01 << 2
#define FLAG_SPACE  0x01 << 3
#define FLAG_PLUS   0x01 << 4

#define LENG_I  0
#define LENG_HH 1
#define LENG_H  2
#define LENG_LL 3
#define LENG_L  4

#define ALLOWED_FLAGS "#0- +"
#define ALLOWED_SPECS "sSpdDioOuUxXcC%"
#define FLAG_OFFSET 0040
#define CONV_OFFSET 0040

/*
 **	TYPEDEF
 */
typedef struct	s_spec{
	int	flags;
	int	width;
	int	prec;
	int	lenght;
	int	conv;
}				t_spec;

/*
 **	PROTOTYPES
 */
int process_directives(char *start, char *end, va_list arg, int fd);

int arg_c_hh(va_list arg, t_spec specs);
int arg_c_l(va_list arg, t_spec specs);
int arg_s_hh(va_list arg, t_spec specs);
int arg_s_l(va_list arg, t_spec specs);

int arg_d_hh(va_list arg, t_spec specs);
int arg_d_h(va_list arg, t_spec specs);
int arg_d_i(va_list arg, t_spec specs);
int arg_d_l(va_list arg, t_spec specs);
int arg_d_ll(va_list arg, t_spec specs);

#endif
