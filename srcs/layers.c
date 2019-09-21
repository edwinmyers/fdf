/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:27:00 by nparker           #+#    #+#             */
/*   Updated: 2019/03/15 16:12:39 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_swap(int *a, int *b)
{
	int			temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void			ft_qsort(t_vector *v, int first, int last)
{
	int i;
	int j;
	int mid;

	i = first;
	j = last;
	mid = (first + last) / 2;
	while (i <= j)
	{
		while (v->data[i] < v->data[mid])
			++i;
		while (v->data[j] > v->data[mid])
			--j;
		if (i <= j)
		{
			ft_swap(&v->data[i], &v->data[j]);
			++i;
			--j;
		}
	}
	if (first < j)
		ft_qsort(v, first, j);
	if (last > i)
		ft_qsort(v, i, last);
}

t_vector		ft_del_rep(t_vector *v)
{
	t_vector	uniq_deps;
	int			i;

	uniq_deps = ft_vec_create(10);
	ft_vec_push_back(&uniq_deps, ft_vec_at(*v, 0));
	i = 1;
	while (i < v->size)
	{
		if (v->data[i] != v->data[i - 1])
			ft_vec_push_back(&uniq_deps, ft_vec_at(*v, i));
		++i;
	}
	return (uniq_deps);
}

t_vector		ft_create_layer_arr(t_pvector *v)
{
	t_vector	all_dep;
	t_vector	uniq;
	int			i;

	i = 0;
	all_dep = ft_vec_create(v->size);
	while (i < v->size)
	{
		ft_vec_push_back(&all_dep, v->point[i].z);
		++i;
	}
	ft_qsort(&all_dep, 0, (int)(all_dep.size - 1));
	uniq = ft_del_rep(&all_dep);
	free(all_dep.data);
	return (uniq);
}

void			ft_color_change(t_pvector *v)
{
	t_vector	uniq_dep;
	int			color;
	int			i;
	int			j;

	uniq_dep = ft_create_layer_arr(v);
	i = 0;
	color = 0x8b1c62;
	while (i < uniq_dep.size)
	{
		j = 0;
		while (j < v->size)
		{
			if (v->point[j].z == uniq_dep.data[i] &&
			v->point[j].orig_color == -1)
			{
				v->point[j].color = color;
				v->point[j].orig_color = color;
			}
			++j;
		}
		color -= 30000;
		++i;
	}
}
