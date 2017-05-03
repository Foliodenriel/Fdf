/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:20:38 by abara             #+#    #+#             */
/*   Updated: 2016/08/25 13:11:48 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

t_winfo	init_winfo(t_object object, char *filename)
{
	t_winfo	winfo;

	winfo.object = object;
	winfo.mlx = mlx_init();
	winfo.win = mlx_new_window(winfo.mlx, WIDTH, HEIGHT,
	ft_strjoin("FdF: ", filename));
	winfo.img = mlx_new_image(winfo.mlx, WIDTH, HEIGHT);
	winfo.fov = FOV;
	winfo.color = (int*)malloc(sizeof(int) * 4);
	winfo.color[0] = 250;
	winfo.color[1] = 250;
	winfo.color[2] = 250;
	winfo.color[3] = 0;
	winfo.background = (int*)malloc(sizeof(int) * 4);
	winfo.background[0] = 0;
	winfo.background[1] = 0;
	winfo.background[2] = 0;
	winfo.background[3] = 0;
	winfo.select = 0;
	winfo.choice = 0;
	return (winfo);
}

int		main(int argc, char **argv)
{
	t_winfo		winfo;
	t_object	object;
	int			**map;
	int			vertex;

	if (argc != 2)
	{
		ft_putendl("\033[1;31merror: Wrong number of argument.");
		return (0);
	}
	map = parse(argv[1], &vertex);
	show_keyinfo();
	object = init_map(map, vertex);
	winfo = init_winfo(object, argv[1]);
	winfo.object = project_everything(winfo.object);
	get_img_info(&winfo, &winfo.bpp, &winfo.line, &winfo.endian);
	render(&winfo);
	mlx_put_image_to_window(winfo.mlx, winfo.win, winfo.img, 0, 0);
	mlx_hook(winfo.win, 2, 1, key_press, &winfo);
	mlx_loop(winfo.mlx);
	return (0);
}
