/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:33:57 by nparker           #+#    #+#             */
/*   Updated: 2019/03/15 16:14:39 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_menu(t_map *map)
{
	int		y;
	int		color;

	color = 0xffd700;
	y = 0;
	mlx_string_put(map->mlx.ptr, map->mlx.win,
	65, y += 20, color, "How to Use");
	mlx_string_put(map->mlx.ptr, map->mlx.win, 15,
	y += 35, color, "Zoom: Scroll mouse");
	mlx_string_put(map->mlx.ptr, map->mlx.win, 15,
	y += 30, color, "Move: Arrows");
	mlx_string_put(map->mlx.ptr, map->mlx.win, 15,
	y += 30, color, "Rotate:");
	mlx_string_put(map->mlx.ptr, map->mlx.win, 57,
	y += 25, color, "X-Axis - 2/8");
	mlx_string_put(map->mlx.ptr, map->mlx.win, 57,
	y += 25, color, "Y-Axis - 4/6");
	mlx_string_put(map->mlx.ptr, map->mlx.win,
	15, y += 30, color, "Fun mode: F key");
	mlx_string_put(map->mlx.ptr, map->mlx.win,
	57, y += 25, color, "ISO: I Key");
}
