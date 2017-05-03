/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:04:09 by abara             #+#    #+#             */
/*   Updated: 2016/08/23 15:23:40 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

t_mapinfo	init_mapinfo(t_mapinfo mapinfo, t_vector v1, t_vector v2)
{
	mapinfo.v1 = v1;
	mapinfo.v2 = v2;
	mapinfo.line = 0;
	mapinfo.vertex = 0;
	return (mapinfo);
}

double		absolute(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int			point_on_screen(int *point)
{
	if ((point[0] >= 0 && point[0] <= WIDTH) &&
	(point[1] >= 0 && point[1] <= HEIGHT))
		return (1);
	return (0);
}

int			get_othervertex(int **map)
{
	int		size;

	size = 0;
	while (map[size] != NULL)
		size++;
	return (size);
}

void		show_keyinfo(void)
{
	ft_putstr("\033[1;33mUp Arrow:\033[0;33m Move Forward		");
	ft_putstr("\033[1;33mDown Arrow:\033[0;33m Move Backward\n");
	ft_putstr("\033[1;33mLeft Arrow:\033[0;33m Turn Left		");
	ft_putstr("\033[1;33mRight Arrow:\033[0;33m Turn Right\n");
	ft_putstr("\033[1;32m------------------------------------------");
	ft_putstr("---------------\n");
	ft_putstr("\033[1;33mR key:\033[0;33m Select red color		");
	ft_putstr("\033[1;33mV key:\033[0;33m Select green color\n");
	ft_putstr("\033[1;33mB key:\033[0;33m Select blue color	");
	ft_putstr("\033[1;33mC key:\033[0;33m Turn to Background");
	ft_putstr("/object color selection\n");
	ft_putstr("\033[1;33m+ Numpad:\033[0;33mAdd selected color	");
	ft_putstr("\033[1;33m- Numpad:\033[0;33mSubtract selected color\n");
	ft_putstr("\033[1;32m------------------------------------------");
	ft_putstr("---------------\n");
	ft_putstr("\033[1;33m7 Numpad:\033[0;33m Rotate xy +		");
	ft_putstr("\033[1;33m4 Numpad:\033[0;33m Rotate xy -\n");
	ft_putstr("\033[1;33m8 Numpad:\033[0;33m Rotate xz +		");
	ft_putstr("\033[1;33m5 Numpad:\033[0;33m Rotate xz -\n");
	ft_putstr("\033[1;33m9 Numpad:\033[0;33m Rotate yz +		");
	ft_putstr("\033[1;33m6 Numpad:\033[0;33m Rotate yz -\n");
}
