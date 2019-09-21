/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:20:47 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 14:08:56 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*ft_pvec_at(t_pvector v, int index)
{
	if (index >= v.size)
		return (NULL);
	return (&v.point[index]);
}

t_pvector		ft_pvec_create(int size)
{
	t_pvector	v;

	v.point = (t_point *)malloc(sizeof(t_point) * size);
	v.size = 0;
	v.capacity = size;
	return (v);
}

void			ft_pvec_push_back(t_pvector *v, t_point elem)
{
	if (v->capacity == v->size)
		ft_pvec_resize(v);
	v->point[v->size] = elem;
	v->size++;
}

void			ft_pvec_resize(t_pvector *v)
{
	t_point		*new_data;
	int			i;

	i = 0;
	new_data = (t_point *)malloc(sizeof(t_point) * v->size);
	while (i < v->size)
	{
		new_data[i] = v->point[i];
		i++;
	}
	free(v->point);
	v->capacity *= 2;
	v->point = (t_point *)malloc(v->capacity * sizeof(t_point));
	i = 0;
	while (i < v->size)
	{
		v->point[i] = new_data[i];
		i++;
	}
	free(new_data);
}
