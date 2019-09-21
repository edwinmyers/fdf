/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:16:20 by nparker           #+#    #+#             */
/*   Updated: 2019/02/04 14:45:43 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_pushback(t_list **head, t_list *elem)
{
	t_list *tmp;

	if (*head == NULL)
	{
		*head = ft_lstnew(elem->content, elem->content_size);
		return ;
	}
	else
		tmp = *head;
	while ((*head)->next != NULL)
		(*head) = (*head)->next;
	(*head)->next = ft_lstnew(elem->content, elem->content_size);
	*head = tmp;
}
