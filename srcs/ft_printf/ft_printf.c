#include "ft_printf.h"
#include <stdio.h>

int		ft_vsnprintf(char *str, size_t size, char *format, va_list arg)
{
	return(vsnprintf(str, size, format, arg));
}

int		ft_vfprintf(FILE *stream, char *format, va_list arg)
{
	return(vfprintf(stream, format, arg));
}

int		ft_vdprintf(int fd, char *format, va_list arg)
{
	int len;
	char *start;
	char *end;
	char *all_specs;

	len = 0;
	all_specs = ft_strdup(ALLOWED_SPECS);
	start = format;
	while ((end = ft_strchr(start, '%')))
	{
		ft_putnstr_fd(start, end - start, fd);
		len += end - start;
		start = end++;
		while (*end != '\0')
		{
			if (ft_strchr(all_specs, *end) != NULL)
			{
				len += process_directives(start, end, arg, fd);
				start = end;
				break;
			}
			end++;
		}
		start++;
	}
	ft_putstr_fd(start, fd);
	ft_strdel(&all_specs);
	return(len += ft_strlen(start));
}

int		ft_vprintf(char *format, va_list arg)
{
	ft_vfprintf(stdout, format, arg);
	return(0);
}

////

int		ft_snprintf(char *str, size_t size, char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = ft_vsnprintf(str, size, format, arg);
	va_end(arg);
	return(ret);
}

int		ft_fprintf(FILE *stream, char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = ft_vfprintf(stream, format, arg);
	va_end(arg);
	return(ret);
}

int		ft_dprintf(int fd, char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = ft_vdprintf(fd, format, arg);
	va_end(arg);
	return(ret);
}

int		ft_printf(char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = ft_vdprintf(1, format, arg);
	va_end(arg);
	return(ret);
}

