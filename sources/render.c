/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:44:06 by abara             #+#    #+#             */
/*   Updated: 2016/08/25 14:34:45 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

void		projection_help(double *position, int *x, int *y)
{
	double	res;
	double	fv;

	fv = FOV / 2;
	if (position[0] != 0)
	{
		res = fv / (atan(absolute(position[0]) / position[2]) * TURN);
		if (position[0] < 0)
			*x = (WIDTH / 2) - ((WIDTH / 2) / res) + 0.5;
		else
			*x = (WIDTH / 2) + ((WIDTH / 2) / res) + 0.5;
	}
	else
		*x = WIDTH / 2;
	if (position[1] != 0)
	{
		res = fv / (atan(absolute(position[1]) / position[2]) * TURN);
		if (position[1] < 0)
			*y = (HEIGHT / 2) + ((HEIGHT / 2) / res) + 0.5;
		else
			*y = (HEIGHT / 2) - ((HEIGHT / 2) / res) + 0.5;
	}
	else
		*y = HEIGHT / 2;
}

int			*projection(double *position)
{
	int		*pos;
	int		x;
	int		y;

	pos = (int*)malloc(sizeof(int) * 4);
	projection_help(position, &x, &y);
	pos[0] = x;
	pos[1] = y;
	pos[2] = position[2];
	pos[3] = atan(absolute(position[1]) / position[2]) * TURN;
	return (pos);
}

t_object	project_everything(t_object object)
{
	int	a;
	int	*pos;

	a = 0;
	pos = (int*)malloc(sizeof(int) * 4);
	while (a != (object.vertex * object.othervertex))
	{
		pos = projection(object.pos3d[a]);
		object.pos2d[a] = pos;
		a++;
	}
	return (object);
}

void		render_help(t_winfo *winfo, int index)
{
	if ((index + 1) % winfo->object.vertex != 0 &&
	index != (winfo->object.vertex * winfo->object.othervertex) - 1 &&
	(winfo->object.pos2d[index][2] >= 0 &&
	winfo->object.pos2d[index][2] >= 0))
	{
		if (point_on_screen(winfo->object.pos2d[index]) == 1 &&
		point_on_screen(winfo->object.pos2d[index]) == 1)
			create_line(winfo, winfo->object.pos2d[index],
			winfo->object.pos2d[index + 1]);
	}
	if (index >= winfo->object.vertex &&
	(winfo->object.pos2d[index][2] >= 0 &&
	winfo->object.pos2d[index - winfo->object.vertex] >= 0))
	{
		if (point_on_screen(winfo->object.pos2d[index]) == 1 &&
		point_on_screen(winfo->object.pos2d[index]) == 1)
			create_line(winfo, winfo->object.pos2d[index],
			winfo->object.pos2d[index - winfo->object.vertex]);
	}
}

void		render(t_winfo *winfo)
{
	int	index;

	index = 0;
	while (index != (winfo->object.vertex * winfo->object.othervertex) != 0)
	{
		render_help(winfo, index);
		index++;
	}
}
