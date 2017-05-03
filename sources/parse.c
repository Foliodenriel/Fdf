/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:19:00 by abara             #+#    #+#             */
/*   Updated: 2016/08/25 13:05:38 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

int		**parse_get_sizemap(char *filename)
{
	char	*line;
	int		**map;
	int		index;
	int		fd;

	index = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		index++;
	map = (int**)malloc(sizeof(int*) * index + 1);
	map[index] = NULL;
	return (map);
}

int		parse_get_maxmap(char *filename)
{
	char	**filesplit;
	char	*line;
	int		index;
	int		max;
	int		fd;

	max = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		index = 0;
		filesplit = ft_strsplit(line, ' ');
		while (filesplit[index] != NULL)
			index++;
		if (max < index)
			max = index;
	}
	return (max);
}

int		*parse_get_split_int(char *line, int max)
{
	char	**strsplit;
	int		*map;
	int		index;

	index = 0;
	map = (int*)malloc(sizeof(int) * max + 1);
	strsplit = ft_strsplit(line, ' ');
	while (strsplit[index] != NULL)
	{
		map[index] = ft_atoi(strsplit[index]);
		index++;
	}
	return (map);
}

int		**parse_get_map(int **map, int *max, char *filename)
{
	char	*line;
	int		fd;
	int		index;

	index = 0;
	*max = parse_get_maxmap(filename);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map[index] = parse_get_split_int(line, *max);
		index++;
	}
	return (map);
}

int		**parse(char *filename, int *max)
{
	int		**map;

	map = parse_get_sizemap(filename);
	map = parse_get_map(map, max, filename);
	return (map);
}
