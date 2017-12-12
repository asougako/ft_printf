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

char	*ft_itoa(int64_t n)
{
	uint64_t	un;
	char		*dst;
	char		*tmp;

	if (n < 0)
	{
		if (!(dst = ft_strnew(ft_intlen(n, 10))))
			return(NULL);
		un = twos_complement(n);
		*dst = '-';
		tmp = ft_itoabase(un, "0123456789");
		ft_strcpy(dst + 1, tmp);
		ft_strdel(&tmp);
		return(dst);
	}
	else
	{
		return(ft_itoabase(n, "0123456789"));
	}
}

