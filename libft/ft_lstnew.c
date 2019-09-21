/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:20:08 by nparker           #+#    #+#             */
/*   Updated: 2019/02/04 14:45:06 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_list;

	new_list = (t_list *)malloc(sizeof(*new_list));
	if (!new_list)
		return (0);
	if (!content)
	{
		new_list->content = 0;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = malloc(content_size);
		if (!new_list)
			return (0);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
