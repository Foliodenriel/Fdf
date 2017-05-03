/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:09:53 by abara             #+#    #+#             */
/*   Updated: 2016/08/25 13:11:33 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

double		**get_pos_malloc(int **map, int vertex)
{
	double		**pos;
	int			size;
	int			index;

	size = 0;
	index = 0;
	while (map[size] != NULL)
		size++;
	pos = (double**)malloc(sizeof(double*) * (vertex * size));
	while (index != (vertex * size))
	{
		pos[index] = (double*)malloc(sizeof(double) * 3);
		index++;
	}
	return (pos);
}

double		**pos_condition(t_mapinfo mapinfo, double **pos, int vertex, int p)
{
	if (p == 0)
	{
		pos[0][0] = -vertex / 2;
		pos[0][1] = vertex / 2;
		pos[0][2] = vertex;
	}
	else if ((p % vertex) == 0)
	{
		pos[p] = add_vector(pos[p - vertex], mapinfo.v2);
		pos[p][2] = vertex - mapinfo.map[mapinfo.line][mapinfo.vertex];
	}
	else
	{
		pos[p] = add_vector(pos[p - 1], mapinfo.v1);
		pos[p][2] = vertex - mapinfo.map[mapinfo.line][mapinfo.vertex];
	}
	return (pos);
}

double		**get_pos(t_mapinfo mapinfo, int vertex, t_vector v1, t_vector v2)
{
	double		**pos;
	int			**map;
	int			p;

	p = 0;
	map = mapinfo.map;
	pos = mapinfo.pos;
	mapinfo = init_mapinfo(mapinfo, v1, v2);
	while (map[mapinfo.line] != NULL)
	{
		mapinfo.vertex = 0;
		while (mapinfo.vertex < vertex)
		{
			pos = pos_condition(mapinfo, pos, vertex, p);
			p++;
			mapinfo.vertex++;
		}
		mapinfo.line++;
	}
	return (pos);
}

double		**create_map(int vertex, int **map)
{
	t_mapinfo	mapinfo;
	t_vector	v1;
	t_vector	v2;
	double		**pos;
	double		z;

	v1 = init_vector(1, 0, 0);
	v2 = init_vector(0, -1, 0);
	z = (double)vertex;
	pos = get_pos_malloc(map, vertex);
	mapinfo.map = map;
	mapinfo.pos = pos;
	pos = get_pos(mapinfo, vertex, v1, v2);
	return (pos);
}

t_object	init_map(int **map, int vertex)
{
	t_object	object;
	double		**pos;
	int			index;

	index = 0;
	pos = create_map(vertex, map);
	object.pos3d = pos;
	object.vertex = vertex;
	object.othervertex = get_othervertex(map);
	object.pos2d = (int**)malloc(sizeof(int*) * (vertex * object.othervertex));
	while (index != (vertex * object.othervertex))
	{
		object.pos2d[index] = (int*)malloc(sizeof(int) * 4);
		index++;
	}
	return (object);
}
