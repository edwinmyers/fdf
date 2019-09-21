/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:08:58 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 12:27:46 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_xrotate(t_point *point, double angle, t_map *map)
{
	double	x1;
	double	y1;
	double	z1;

	x1 = point->x;
	y1 = point->y * cos(angle) + point->z * sin(angle);
	z1 = -point->y * sin(angle) + point->z * cos(angle);
	point->x = x1;
	point->y = y1;
	point->z = z1;
	if (map->fun_toggle == 0)
		point->color = point->orig_color;
	else
		point->color = ft_random(map, 0);
}

void		ft_yrotate(t_point *point, double angle, t_map *map)
{
	double	x1;
	double	y1;
	double	z1;

	x1 = point->x * cos(angle) + point->z * sin(angle);
	y1 = point->y;
	z1 = -point->x * sin(angle) + point->z * cos(angle);
	point->x = x1;
	point->y = y1;
	point->z = z1;
	if (map->fun_toggle == 0)
		point->color = point->orig_color;
	else
		point->color = ft_random(map, 1);
}

void		ft_zrotate(t_point *point, double angle, t_map *map)
{
	double	x1;
	double	y1;
	double	z1;

	x1 = point->x * cos(angle) - point->y * sin(angle);
	y1 = point->x * sin(angle) + point->y * cos(angle);
	z1 = point->z;
	point->x = x1;
	point->y = y1;
	point->z = z1;
	if (map->fun_toggle == 0)
		point->color = point->orig_color;
	else
		point->color = ft_random(map, 0);
}

void		ft_rotate_all(t_map *map, double angle, int n)
{
	int		i;

	i = 0;
	mlx_clear_window(map->mlx.ptr, map->mlx.win);
	while (i < map->pvec.size)
	{
		if (n == 0)
			ft_xrotate(ft_pvec_at(map->pvec, i), angle, map);
		else if (n == 1)
			ft_yrotate(ft_pvec_at(map->pvec, i), angle, map);
		else if (n == 2)
			ft_zrotate(ft_pvec_at(map->pvec, i), angle, map);
		i++;
	}
}
