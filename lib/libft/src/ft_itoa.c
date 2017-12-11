/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:00 by asougako          #+#    #+#             */
/*   Updated: 2017/12/11 16:22:49 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int64_t n)
{
	uint64_t	un;
	char		*dst;
	char		*tmp;
	int			index;

	index = 0;
	if (!(dst = ft_strnew(ft_intlen(n, 10))))
		return(NULL);
	if (n < 0)
	{
		un = twos_complement(n);
		*dst = '-';
		tmp = ft_itoabase(un, "0123456789");
		while ((*(dst + index + 1) = *(tmp + index)) != '\0')
			index++;
	}
	else
	{
		return(ft_itoabase(n, "0123456789"));
	}
	ft_strdel(&tmp);
	return(dst);
}

char	*ft_itoa2(int64_t n)
{
	uint64_t	u_n;
	char		*dst;
	char		*tmp1;
	char		*tmp2;

	dst = ft_strnew(0);
	tmp1 = dst;
	u_n = (uint64_t)n;
	if ((n >> (sizeof(n) * 8 - 1)) & 1)
	{
		u_n = twos_complement(n);
		dst = ft_strjoin(dst, "-");
	}
	tmp2 = ft_itoabase(u_n, "0123456789");
	dst = ft_strjoin(dst, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (dst);
}
