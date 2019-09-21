/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:23:51 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 13:55:50 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_map		map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf file_name\n");
		exit(-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(-1);
	map = ft_map_init();
	if (ft_read_map(fd, &map) == -1 || read(fd, &map, 0) < 0)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	ft_norm_size(&map);
	ft_color_change(&map.pvec);
	ft_draw_line(&map);
	ft_hook(&map);
	mlx_loop(map.mlx.ptr);
	free(map.pvec.point);
	close(fd);
	exit(0);
}
