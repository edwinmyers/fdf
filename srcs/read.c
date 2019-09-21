/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:27:39 by nparker           #+#    #+#             */
/*   Updated: 2019/03/15 16:16:54 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		destroy(char **arr)
{
	int		i;
	int		len;

	i = 0;
	len = count_lines(arr);
	while (i < len)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}

int			ft_parse_color(char *str)
{
	char	**tmp;
	int		color;

	tmp = ft_strsplit(str, ',');
	if (ft_strcmp(tmp[0], str) == 0)
		color = -1;
	else
		color = ft_hex_to_dec(tmp[1]);
	destroy(tmp);
	return (color);
}

t_point		ft_parse_point(char *str, int x, int y, t_map *map)
{
	t_point tmp_point;

	tmp_point.x = x * map->zoom;
	tmp_point.y = y * map->zoom;
	tmp_point.z = ft_atoi(str) * map->zoom;
	tmp_point.color = ft_parse_color(str);
	if (map->fun_toggle == 0)
	{
		tmp_point.orig_color = tmp_point.color;
	}
	return (tmp_point);
}

int			ft_read_map(int fd, t_map *map)
{
	char	*str;
	char	**temp;
	int		x;
	int		width;

	while (get_next_line(fd, &str) > 0)
	{
		x = -1;
		if (!ft_validate(str))
			return (x);
		temp = ft_strsplit(str, ' ');
		width = count_lines(temp);
		if (map->width && width != map->width)
			return (x);
		if (map->pvec.size == 0)
			map->pvec = ft_pvec_create(width);
		while (++x < width)
			ft_pvec_push_back(&map->pvec,
			ft_parse_point(temp[x], x, map->height, map));
		destroy(temp);
		map->width = width;
		map->height++;
		free(str);
	}
	return (1);
}
