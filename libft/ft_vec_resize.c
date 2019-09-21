/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:46:14 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/05 15:21:35 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_vec_resize(t_vector *v)
{
	int *new_data;
	int i;

	i = 0;
	new_data = (int *)malloc(sizeof(int) * v->size);
	while (i < v->size)
	{
		new_data[i] = v->data[i];
		i++;
	}
	free(v->data);
	v->capacity *= 2;
	v->data = malloc(v->capacity * sizeof(int));
	i = 0;
	while (i < v->size)
	{
		v->data[i] = new_data[i];
		i++;
	}
}
