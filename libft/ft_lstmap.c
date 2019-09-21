/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:35:08 by nparker           #+#    #+#             */
/*   Updated: 2018/12/14 13:33:36 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *list;
	t_list *head;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	head = list;
	lst = lst->next;
	while (lst)
	{
		new_list = f(lst);
		list->next = new_list;
		list = new_list;
		lst = lst->next;
	}
	return (head);
}
