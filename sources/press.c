/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:53:55 by abara             #+#    #+#             */
/*   Updated: 2016/08/23 15:24:30 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

void	get_img_info(t_winfo *winfo, int *bpp, int *line, int *endian)
{
	int	index;
	int	i;

	index = 0;
	winfo->img = mlx_new_image(winfo->mlx, WIDTH, HEIGHT);
	winfo->data = mlx_get_data_addr(winfo->img, bpp, line, endian);
	while (index != (*line * HEIGHT))
	{
		i = 0;
		while (i != 4)
		{
			if (i == 0)
				winfo->data[index] = winfo->background[0];
			else if (i == 1)
				winfo->data[index] = winfo->background[1];
			else if (i == 2)
				winfo->data[index] = winfo->background[2];
			else if (i == 3)
				winfo->data[index] = winfo->background[3];
			index++;
			i++;
		}
	}
}

void	press_move(int key, t_winfo *winfo)
{
	if (key == 125)
		winfo->object = move_forward(winfo->object);
	else if (key == 126)
		winfo->object = move_backward(winfo->object);
	else if (key == 123)
		winfo->object = turn_left_right(winfo->object, -1);
	else if (key == 124)
		winfo->object = turn_left_right(winfo->object, 1);
}

void	press_color(int key, t_winfo *winfo)
{
	if (key == 15)
		winfo->select = 2;
	else if (key == 9)
		winfo->select = 1;
	else if (key == 11)
		winfo->select = 0;
	else if (key == 69 || key == 78)
		press_color_help(key, winfo);
	else if (key == 8)
	{
		if (winfo->choice == 0)
			winfo->choice = 1;
		else
			winfo->choice = 0;
	}
}

void	rotation_key(int key, t_winfo *winfo)
{
	if (key == 89)
		object_rotation_xy(winfo, 1);
	else if (key == 86)
		object_rotation_xy(winfo, -1);
	else if (key == 91)
		object_rotation_xz(winfo, 1);
	else if (key == 87)
		object_rotation_xz(winfo, -1);
	else if (key == 92)
		object_rotation_yz(winfo, 1);
	else
		object_rotation_yz(winfo, -1);
}

int		key_press(int key, void *param)
{
	t_winfo	*winfo;

	winfo = param;
	if (key == 53)
		exit(1);
	else if (key == 125 || key == 126 || key == 123 || key == 124)
		press_move(key, winfo);
	else if (key == 15 || key == 9 || key == 11 ||
	key == 69 || key == 78 || key == 8)
		press_color(key, winfo);
	else if (key == 89 || key == 86 || key == 91 ||
	key == 87 || key == 92 || key == 88)
		rotation_key(key, winfo);
	winfo->object = project_everything(winfo->object);
	get_img_info(winfo, &winfo->bpp, &winfo->line, &winfo->endian);
	render(winfo);
	mlx_put_image_to_window(winfo->mlx, winfo->win, winfo->img, 0, 0);
	return (0);
}
