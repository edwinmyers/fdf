/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:28:08 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 12:58:33 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_data		ft_mlx_init(void)
{
	t_mlx_data	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "fdf");
	return (mlx);
}

t_map			ft_map_init(void)
{
	t_map		map;

	map.mlx = ft_mlx_init();
	map.width = 0;
	map.height = 0;
	map.zoom = 1;
	map.c_x = 0;
	map.c_y = 0;
	map.pvec = ft_pvec_create(10);
	map.color = 0xcd853f;
	map.fun_toggle = 0;
	map.fun = 0x0;
	return (map);
}

void			ft_hook(t_map *map)
{
	mlx_hook(map->mlx.win, 2, 0, ft_key_press, map);
	mlx_hook(map->mlx.win, 4, 0, ft_mouse_press, map);
	mlx_hook(map->mlx.win, 17, 0, ft_close, NULL);
}

void			ft_take_size(t_map *map)
{
	int i;

	i = 0;
	while (i < (map->width * map->height))
	{
		map->pvec.point[i].x *= map->zoom;
		map->pvec.point[i].y *= map->zoom;
		map->pvec.point[i].z *= map->zoom;
		++i;
	}
}

void			ft_norm_size(t_map *map)
{
	map->zoom = ft_min(WIDTH / 2 / map->width, HEIGHT / 2 / map->height);
	map->c_x = (WIDTH - map->width * map->zoom) / 2;
	map->c_y = (HEIGHT - map->height * map->zoom) / 2;
	ft_take_size(map);
}
