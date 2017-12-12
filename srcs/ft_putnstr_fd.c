/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:21:28 by asougako          #+#    #+#             */
/*   Updated: 2016/12/13 13:45:56 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnstr_fd(const char *str, size_t size, int fd)
{
	char	*tmp;

	tmp = (char*)str;
	write(fd, tmp, size);
}
