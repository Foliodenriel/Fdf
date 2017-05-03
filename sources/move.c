/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:04:38 by abara             #+#    #+#             */
/*   Updated: 2016/08/23 15:24:03 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

t_object	move_forward(t_object object)
{
	int	index;

	index = 0;
	while (index != (object.vertex * object.othervertex))
	{
		object.pos3d[index][2] += 0.1;
		index++;
	}
	return (object);
}

t_object	move_backward(t_object object)
{
	int	index;

	index = 0;
	while (index != (object.vertex * object.othervertex))
	{
		object.pos3d[index][2] -= 0.1;
		index++;
	}
	return (object);
}

t_object	turn_left_right(t_object object, double angle)
{
	int	index;

	index = 0;
	while (index != (object.vertex * object.othervertex))
	{
		object.pos3d[index] = rotate_xz(object.pos3d[index], angle);
		index++;
	}
	return (object);
}
