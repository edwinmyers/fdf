/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:45:18 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/06 16:03:27 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		ft_vec_create(int size)
{
	t_vector	v;

	v.data = (int *)malloc(sizeof(int) * size);
	v.size = 0;
	v.capacity = size;
	return (v);
}
