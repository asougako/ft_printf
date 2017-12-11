/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_intlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:54:56 by asougako          #+#    #+#             */
/*   Updated: 2017/12/11 15:39:45 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int64_t i, size_t base)
{
	size_t		count;
	uint64_t	ui;

	count = 0;
	if (i == 0)
	{
		return (1);
	}
	if (i < 0)
	{
		ui = twos_complement(i);
		count++;
	}
	else
	{
		ui = (uint64_t)i;
	}
	while (ui > 0)
	{
		ui /= base;
		count++;
	}
	return (count);
}
