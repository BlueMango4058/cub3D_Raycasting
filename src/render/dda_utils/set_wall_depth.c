/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_depth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:43:44 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/16 18:30:09 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/*
** Computes the final wall depth.
**
** Uses the last stepped side to get
** the exact depth where the ray hit the wall.
** Clamps the value to avoid zero or negative depth.
*/
void	set_wall_depth(t_dda *d)
{
	if (d->side == 0)
	{
		d->wall_depth = d->side_time.x - d->delta_time.x;
	}
	else if (d->side == 1)
	{
		d->wall_depth = d->side_time.y - d->delta_time.y;
	}
	if (d->wall_depth < 0.0001)
		d->wall_depth = 0.0001;
}
