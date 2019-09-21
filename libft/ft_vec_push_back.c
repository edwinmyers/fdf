/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:47:10 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/05 15:17:01 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vec_push_back(t_vector *v, int elem)
{
	if (v->capacity == v->size)
		ft_vec_resize(v);
	v->data[v->size] = elem;
	v->size++;
}
