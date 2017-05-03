/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:24:05 by abara             #+#    #+#             */
/*   Updated: 2016/08/25 13:12:58 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

void	put_pixel(t_winfo *winfo, int x, int y, int *color)
{
	int	index;

	index = y * winfo->line - (winfo->line - (x * (winfo->line / WIDTH)));
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT) && index >= 0)
	{
		if (winfo->data[index] != color[0])
			winfo->data[index] = color[0];
		if (winfo->data[index] != color[1])
			winfo->data[index + 1] = color[1];
		if (winfo->data[index] != color[2])
			winfo->data[index + 2] = color[2];
		if (winfo->data[index] != color[3])
			winfo->data[index + 3] = color[3];
	}
}

void	create_line_if(t_winfo *winfo, int *p1, int *p2)
{
	int		x;
	int		y;
	double	dx;
	double	dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	x = p1[0];
	while (x != p2[0])
	{
		y = p1[1] + dy * (x - p1[0]) / dx;
		put_pixel(winfo, x, y, winfo->color);
		x++;
	}
}

void	create_line_else(t_winfo *winfo, int *p1, int *p2)
{
	int		x;
	int		y;
	double	dx;
	double	dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	y = p1[1];
	while (y != p2[1])
	{
		x = p1[0] + dx * (y - p1[1]) / dy;
		put_pixel(winfo, x, y, winfo->color);
		(dy < 0) ? y-- : y++;
	}
}

void	create_line(t_winfo *winfo, int *p1, int *p2)
{
	int		*p3;
	double	dx;
	double	dy;

	if (p1[0] > p2[0])
	{
		p3 = p1;
		p1 = p2;
		p2 = p3;
	}
	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (absolute(dx) >= absolute(dy))
		create_line_if(winfo, p1, p2);
	else
		create_line_else(winfo, p1, p2);
}

void	press_color_help(int key, t_winfo *winfo)
{
	if (key == 69)
	{
		if (winfo->choice == 0 && winfo->background[winfo->select] + 10 <= 255)
			winfo->background[winfo->select] += 10;
		else if (winfo->choice == 1 && winfo->color[winfo->select] + 10 <= 255)
			winfo->color[winfo->select] += 10;
	}
	else
	{
		if (winfo->choice == 0 && winfo->background[winfo->select] - 10 >= 0)
			winfo->background[winfo->select] -= 10;
		else if (winfo->choice == 1 && winfo->color[winfo->select] - 10 >= 0)
			winfo->color[winfo->select] -= 10;
	}
}
