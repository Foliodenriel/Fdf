/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:11:28 by abara             #+#    #+#             */
/*   Updated: 2016/12/09 14:09:19 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft/libft.h"
# include "mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define FOV 60
# define TURN (180/M_PI)

typedef struct	s_vector
{
	double		*tuple;
}				t_vector;

typedef struct	s_object
{
	double		**pos3d;
	int			**pos2d;
	int			vertex;
	int			othervertex;
}				t_object;

typedef struct	s_winfo
{
	t_object	object;
	char		*data;
	void		*mlx;
	void		*win;
	void		*img;
	int			*color;
	int			*background;
	int			fov;
	int			bpp;
	int			line;
	int			endian;
	int			select;
	int			choice;
}				t_winfo;

typedef struct	s_mapinfo
{
	t_vector	v1;
	t_vector	v2;
	double		**pos;
	int			**map;
	int			line;
	int			vertex;
}				t_mapinfo;

t_object		init_map(int **map, int vertex);
t_object		project_everything(t_object object);
t_object		move_forward(t_object object);
t_object		move_backward(t_object object);
t_object		turn_left_right(t_object object, double angle);
t_mapinfo		init_mapinfo(t_mapinfo mapinfo, t_vector v1, t_vector v2);
t_vector		init_vector(double x, double y, double z);
t_vector		get_vector(double *p1, double *p2);
double			*add_vector(double *pos, t_vector vector);
double			*rotate_xy(double *pos, double angle);
double			*rotate_xz(double *pos, double angle);
double			*rotate_yz(double *pos, double angle);
double			absolute(double nb);
void			get_img_info(t_winfo *winfo, int *bpp, int *line, int *endian);
void			create_line(t_winfo *winfo, int *p1, int *p2);
void			put_pixel(t_winfo *winfo, int x, int y, int *color);
void			press_color_help(int key, t_winfo *winfo);
void			render(t_winfo *winfo);
void			object_rotation_xy(t_winfo *winfo, double angle);
void			object_rotation_xz(t_winfo *winfo, double angle);
void			object_rotation_yz(t_winfo *winfo, double angle);
void			show_keyinfo(void);
int				**parse(char *filename, int *s);
int				key_press(int key, void *param);
int				point_on_screen(int *point);
int				get_othervertex(int **map);

#endif
