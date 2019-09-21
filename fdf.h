/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:51:26 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 12:39:01 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 1080
# define WIDTH  1920
# define C_X WIDTH / 4
# define C_Y HEIGHT / 4
# define GREEN 60928
# include "minilibx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# define ANGLE M_PI / 100

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				orig_color;
	int				color;
}					t_point;

typedef struct		s_pvector
{
	t_point			*point;
	int				size;
	int				capacity;
}					t_pvector;

typedef struct		s_mlx_data
{
	void			*ptr;
	void			*win;
}					t_mlx_data;

typedef struct		s_map
{
	t_mlx_data		mlx;
	int				zoom;
	int				rotx;
	int				roty;
	int				fun_toggle;
	t_pvector		pvec;
	int				width;
	int				height;
	int				toggle;
	int				iso_tog;
	int				fun;
	int				color;
	int				c_x;
	int				c_y;
}					t_map;

t_pvector			ft_pvec_create(int size);
void				ft_pvec_resize(t_pvector *v);
void				ft_pvec_push_back(t_pvector *v, t_point elem);
t_point				*ft_pvec_at(t_pvector v, int index);
void				ft_iso_p(double *x, double *y, double *z);
void				ft_iso(t_map *map);
void				ft_line_low(t_point *p1, t_point *p2,
t_map *map, t_point *delta);
void				ft_line_high(t_point *p1, t_point *p2,
t_map *map, t_point *delta);
void				ft_choose_line(t_point p0, t_point p1, t_map *map);
int					ft_validate(char *str);
void				ft_draw_line(t_map *map);
int					ft_key_press(int key, t_map *map);
t_point				**ft_point_alloc(int n, int m);
void				ft_xrotate(t_point *point, double angle, t_map *map);
void				ft_yrotate(t_point *point, double angle, t_map *map);
void				ft_zrotate(t_point *point, double angle, t_map *map);
void				ft_rotate_all(t_map *map, double angle, int n);
int					ft_mouse_press(int button, int x, int y, t_map *map);
int					ft_mouse_release(int button, int x, int y, t_map *map);
double				ft_percent(int start, int end, int current);
int					ft_get_light(int start, int end, double percentage);
int					ft_get_color(t_point current, t_point start,
								t_point end, t_point delta);
int					ft_validate_color(char *str, int *i);
int					ft_read_map(int fd, t_map *map);
t_point				ft_parse_point(char *str, int x, int y, t_map *map);
void				ft_zoom(t_map *map, int n);
void				ft_move_pic(t_map *map, int n);
int					ft_key_rotate(int key, t_map *map);
int					ft_parse_color(char *str);
int					ft_random(t_map *map, int n);
void				ft_color_change(t_pvector *v);
int					ft_close(void *param);
t_mlx_data			ft_mlx_init(void);
t_map				ft_map_init(void);
void				ft_hook(t_map *map);
void				ft_norm_size(t_map *map);
void				ft_print_menu(t_map *map);

#endif
