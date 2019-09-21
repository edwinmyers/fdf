/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:26:25 by nparker           #+#    #+#             */
/*   Updated: 2019/03/15 16:15:35 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_delta(t_point *p1, t_point *p2, int n)
{
	int		dx;
	int		dy;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	if (n == 0)
		return (dx);
	else if (n == 1)
		return (dy);
	return (0);
}

void		ft_line_low(t_point *p1, t_point *p2, t_map *map,
t_point *delta)
{
	int		d;
	int		yi;
	t_point current;

	current.y = p1->y;
	current.x = p1->x;
	yi = 1;
	if (delta->y < 0)
	{
		yi = -1;
		delta->y = -delta->y;
	}
	d = 2 * delta->y - delta->x;
	while (current.x >= p1->x && current.x <= p2->x)
	{
		mlx_pixel_put(map->mlx.ptr, map->mlx.win, current.x + map->c_x,
		current.y + map->c_y, ft_get_color(current, *p1, *p2, *delta));
		if (d > 0)
		{
			current.y += yi;
			d = d - 2 * delta->x;
		}
		d = d + 2 * delta->y;
		current.x++;
	}
}

void		ft_line_high(t_point *p1, t_point *p2, t_map *map,
t_point *delta)
{
	int		d;
	int		xi;
	t_point current;

	xi = 1;
	current.y = p1->y;
	current.x = p1->x;
	if (delta->x < 0)
	{
		xi = -1;
		delta->x = -delta->x;
	}
	d = 2 * delta->x - delta->y;
	while (current.y >= p1->y && current.y <= p2->y)
	{
		mlx_pixel_put(map->mlx.ptr, map->mlx.win, current.x + map->c_x,
		current.y + map->c_y, ft_get_color(current, *p1, *p2, *delta));
		if (d > 0)
		{
			current.x += xi;
			d = d - 2 * delta->y;
		}
		d = d + 2 * delta->x;
		current.y++;
	}
}

void		ft_choose_line(t_point p1, t_point p2, t_map *map)
{
	t_point	delta;

	delta.x = ft_get_delta(&p1, &p2, 0);
	delta.y = ft_get_delta(&p1, &p2, 1);
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
		if (p1.x > p2.x)
		{
			delta.x = ft_get_delta(&p2, &p1, 0);
			delta.y = ft_get_delta(&p2, &p1, 1);
			ft_line_low(&p2, &p1, map, &delta);
		}
		else
			ft_line_low(&p1, &p2, map, &delta);
	else
	{
		if (p1.y > p2.y)
		{
			delta.x = ft_get_delta(&p2, &p1, 0);
			delta.y = ft_get_delta(&p2, &p1, 1);
			ft_line_high(&p2, &p1, map, &delta);
		}
		else
			ft_line_high(&p1, &p2, map, &delta);
	}
}

void		ft_draw_line(t_map *map)
{
	int		i;

	i = 0;
	ft_print_menu(map);
	while (i < map->pvec.size)
	{
		if ((i + 1) % (map->width) != 0)
			ft_choose_line(*ft_pvec_at(map->pvec, i),
			*ft_pvec_at(map->pvec, i + 1), map);
		if (map->width + i < map->pvec.size)
			ft_choose_line(*ft_pvec_at(map->pvec, i),
			*ft_pvec_at(map->pvec, map->width + i), map);
		i++;
	}
}
