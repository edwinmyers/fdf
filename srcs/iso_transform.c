/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:26:44 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 12:26:47 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_iso_p(double *x, double *y, double *z)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - *z;
}

void		ft_iso(t_map *map)
{
	int		i;
	t_point	*tmp;

	i = 0;
	mlx_clear_window(map->mlx.ptr, map->mlx.win);
	while (i < map->pvec.size)
	{
		tmp = ft_pvec_at(map->pvec, i);
		ft_iso_p(&tmp->x, &tmp->y, &tmp->z);
		i++;
	}
}
