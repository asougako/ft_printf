/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:57:01 by asougako          #+#    #+#             */
/*   Updated: 2017/01/16 19:02:03 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = (t_list *)malloc(sizeof(*new_list))))
		return (NULL);
	if (content == NULL)
	{
		(*new_list).content = NULL;
		(*new_list).content_size = 0;
	}
	else
	{
		if (!((*new_list).content = ft_strnew(content_size)))
			return (NULL);
		ft_memcpy((*new_list).content, (void *)content, content_size);
		(*new_list).content_size = content_size;
	}
	(*new_list).next = NULL;
	return (new_list);
}
