/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raydir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:40:11 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:52:31 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/*
** Calculates the camera plane vector.
** The 0.66 value defines the field of view (FOV)
** and is commonly used for a ~66° horizontal view.
*/
static t_vector	cal_plane(const t_vector player_dir)
{
	t_vector	plane;

	plane.x = -player_dir.y * 0.66;
	plane.y = player_dir.x * 0.66;
	return (plane);
}

void	set_raydir(t_dda *d, const double camera_x)
{
	t_vector	plane;

	plane = cal_plane(d->p_dir);
	d->ray_dir.x = d->p_dir.x + plane.x * camera_x;
	d->ray_dir.y = d->p_dir.y + plane.y * camera_x;
}
