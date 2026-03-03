/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_step_and_side_time.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:42:22 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 16:03:45 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/*
** Sets step direction and initial side time.
**
** The step value decides whether the ray moves
** forward or backward on each axis.
** side_time is the distance from the ray start
** to the first grid border on that axis.
*/
void	set_step_and_side_time(t_dda *d, const t_vector ray)
{
	if (ray.x < 0)
	{
		d->step_x = -1;
		d->side_time.x = (d->pos_x - d->map_x) * d->delta_time.x;
	}
	else
	{
		d->step_x = 1;
		d->side_time.x = (d->map_x + 1.0 - d->pos_x) * d->delta_time.x;
	}
	if (ray.y < 0)
	{
		d->step_y = -1;
		d->side_time.y = (d->pos_y - d->map_y) * d->delta_time.y;
	}
	else
	{
		d->step_y = 1;
		d->side_time.y = (d->map_y + 1.0 - d->pos_y) * d->delta_time.y;
	}
}
