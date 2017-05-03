/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:09:31 by abara             #+#    #+#             */
/*   Updated: 2016/08/23 15:24:45 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

int			absolut(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

t_vector	init_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.tuple = (double*)malloc(sizeof(double) * 3);
	vector.tuple[0] = x;
	vector.tuple[1] = y;
	vector.tuple[2] = z;
	return (vector);
}

double		*add_vector(double *pos, t_vector vector)
{
	double *npos;

	npos = (double*)malloc(sizeof(double) * 3);
	npos[0] = pos[0] + vector.tuple[0];
	npos[1] = pos[1] + vector.tuple[1];
	npos[2] = pos[2] + vector.tuple[2];
	return (npos);
}

t_vector	get_vector(double *p1, double *p2)
{
	t_vector	vector;

	vector.tuple = (double *)malloc(sizeof(double) * 3);
	vector.tuple[0] = p2[0] - p1[0];
	vector.tuple[1] = p2[1] - p1[1];
	vector.tuple[2] = p2[2] - p1[2];
	return (vector);
}
