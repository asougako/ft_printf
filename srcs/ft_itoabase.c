/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:46:57 by asougako          #+#    #+#             */
/*   Updated: 2017/12/11 16:48:00 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char		*ft_itoabase(uint64_t u_n, const char *base)
{
	char			*dst;
	unsigned int	index;
	unsigned int	base_size;

//	ft_putendl("");
//	ft_print_memory(&u_n, 32);
//	ft_putendl("");

	base_size = ft_strlen((char *)base);
	index = ft_uintlen(u_n, base_size) - 1;
	if (!(dst = ft_strnew(index + 1)))
		return (NULL);
	if (u_n == 0)
	{
		*(dst) = '0';
	}
	while ((u_n) > 0)
	{
		*(dst + index--) = (*(base + (u_n % base_size)));
		u_n /= base_size;
	}
	return (dst);
}
