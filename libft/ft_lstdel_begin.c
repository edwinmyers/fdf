/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:10:30 by nparker           #+#    #+#             */
/*   Updated: 2019/02/01 17:23:32 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_begin(t_list **lst)
{
	t_list *begin;

	begin = *lst;
	*lst = (*lst)->next;
	return (begin);
}
