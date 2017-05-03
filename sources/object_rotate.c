/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:47:45 by abara             #+#    #+#             */
/*   Updated: 2016/08/23 15:24:11 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

double	*init_point(void)
{
	double	*init;

	init = (double*)malloc(sizeof(double) * 3);
	init[0] = 0;
	init[1] = 0;
	init[2] = 0;
	return (init);
}

double	*get_center(t_object object)
{
	int		index;
	double	*center;

	index = 0;
	center = (double*)malloc(sizeof(double) * 3);
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;
	while (index != (object.vertex * object.othervertex))
	{
		center[0] += object.pos3d[index][0];
		center[1] += object.pos3d[index][1];
		center[2] += object.pos3d[index][2];
		index++;
	}
	center[0] /= index;
	center[1] /= index;
	center[2] /= index;
	return (center);
}

void	object_rotation_xy(t_winfo *winfo, double angle)
{
	double		*center;
	t_vector	vector;
	int			index;

	index = 0;
	center = get_center(winfo->object);
	while (index != (winfo->object.vertex * winfo->object.othervertex))
	{
		vector = get_vector(center, init_point());
		winfo->object.pos3d[index] =
		add_vector(winfo->object.pos3d[index], vector);
		winfo->object.pos3d[index] =
		rotate_xy(winfo->object.pos3d[index], angle);
		vector = get_vector(init_point(), center);
		winfo->object.pos3d[index] =
		add_vector(winfo->object.pos3d[index], vector);
		index++;
	}
}

void	object_rotation_xz(t_winfo *winfo, double angle)
{
	double		*center;
	t_vector	vector;
	int			index;

	index = 0;
	center = get_center(winfo->object);
	while (index != (winfo->object.vertex * winfo->object.othervertex))
	{
		vector = get_vector(center, init_point());
		winfo->object.pos3d[index] =
		add_vector(winfo->object.pos3d[index], vector);
		winfo->object.pos3d[index] =
		rotate_xz(winfo->object.pos3d[index], angle);
		vector = get_vector(init_point(), center);
		winfo->object.pos3d[index] =
		add_vector(winfo->object.pos3d[index], vector);
		index++;
	}
}

void	object_rotation_yz(t_winfo *winfo, double angle)
{
	double		*center;
	t_vector	vector;
	int			index;

	index = 0;
	center = get_center(winfo->object);
	while (index != (winfo->object.vertex * winfo->object.othervertex))
	{
		vector = get_vector(center, init_point());
		winfo->object.pos3d[index] =
		add_vector(winfo->object.pos3d[index], vector);
		winfo->object.pos3d[index] =
		rotate_yz(winfo->object.pos3d[index], angle);
		vector = get_vector(init_point(), center);
		winfo->object.pos3d[index] =
		add_vector(winfo->object.pos3d[index], vector);
		index++;
	}
}
