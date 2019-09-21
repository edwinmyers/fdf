/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:26:53 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 13:38:31 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_rotate(int key, t_map *map)
{
	if (key == 88)
	{
		ft_rotate_all(map, ANGLE, 1);
		ft_draw_line(map);
	}
	if (key == 86)
	{
		ft_rotate_all(map, -ANGLE, 1);
		ft_draw_line(map);
	}
	if (key == 91)
	{
		ft_rotate_all(map, -ANGLE, 0);
		ft_draw_line(map);
	}
	if (key == 84)
	{
		ft_rotate_all(map, ANGLE, 0);
		ft_draw_line(map);
	}
	return (0);
}

int		ft_mouse_press(int button, int x, int y, t_map *map)
{
	if (button == 1)
	{
		map->rotx = x;
		map->roty = y;
		map->toggle = 1;
	}
	if (button == 4)
	{
		ft_zoom(map, 0);
		ft_draw_line(map);
	}
	if (button == 5)
	{
		ft_zoom(map, 1);
		ft_draw_line(map);
	}
	return (0);
}

void	ft_key_move(int key, t_map *map)
{
	if (key == 125)
		ft_move_pic(map, 2);
	if (key == 126)
		ft_move_pic(map, 3);
	if (key == 123)
		ft_move_pic(map, 0);
	if (key == 124)
		ft_move_pic(map, 1);
}

int		ft_key_press(int key, t_map *map)
{
	if (key == 125 || key == 126 || key == 124 || key == 123)
		ft_key_move(key, map);
	if (key == 86 || key == 88 || key == 84 || key == 91)
		ft_key_rotate(key, map);
	if (key == 34)
	{
		map->iso_tog = 1;
		ft_iso(map);
		ft_draw_line(map);
	}
	if (key == 3)
		map->fun_toggle = 1;
	if (key == 12)
	{
		map->fun_toggle = 0;
		map->iso_tog = 0;
	}
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}
