/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:20:45 by nparker           #+#    #+#             */
/*   Updated: 2019/03/15 16:17:14 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_zoom(t_map *map, int n)
{
	int		i;
	t_point *temp;

	i = -1;
	mlx_clear_window(map->mlx.ptr, map->mlx.win);
	while (++i < map->pvec.size)
	{
		temp = ft_pvec_at(map->pvec, i);
		if (n == 0)
		{
			temp->x *= 1.2;
			temp->z *= 1.2;
			temp->y *= 1.2;
		}
		else if (n == 1)
		{
			temp->x /= 1.2;
			temp->y /= 1.2;
			temp->z /= 1.2;
		}
	}
}

void		ft_move_pic(t_map *map, int n)
{
	int		i;
	t_point *temp;

	i = -1;
	mlx_clear_window(map->mlx.ptr, map->mlx.win);
	while (++i < map->pvec.size)
	{
		temp = ft_pvec_at(map->pvec, i);
		if (n == 0)
			temp->x -= 20;
		else if (n == 1)
			temp->x += 20;
		else if (n == 2)
			temp->y += 20;
		else if (n == 3)
			temp->y -= 20;
	}
	ft_draw_line(map);
}
