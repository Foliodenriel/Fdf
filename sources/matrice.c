/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:23:06 by abara             #+#    #+#             */
/*   Updated: 2016/08/23 15:23:56 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fdf.h"

double		*rotate_xy(double *pos, double angle)
{
	pos[0] = pos[0] * cos(angle / (180 / M_PI)) +
	pos[1] * sin(angle / (180 / M_PI));
	pos[1] = pos[0] * -sin(angle / (180 / M_PI)) +
	pos[1] * cos(angle / (180 / M_PI));
	return (pos);
}

double		*rotate_xz(double *pos, double angle)
{
	pos[0] = pos[0] * cos(angle / (180 / M_PI)) +
	pos[2] * -sin(angle / (180 / M_PI));
	pos[2] = pos[0] * sin(angle / (180 / M_PI)) +
	pos[2] * cos(angle / (180 / M_PI));
	return (pos);
}

double		*rotate_yz(double *pos, double angle)
{
	pos[1] = pos[1] * cos(angle / (180 / M_PI)) +
	pos[2] * sin(angle / (180 / M_PI));
	pos[2] = pos[1] * -sin(angle / (180 / M_PI)) +
	pos[2] * cos(angle / (180 / M_PI));
	return (pos);
}
