/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_delta_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:41:44 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 16:03:01 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <math.h>

/*
** Calculates delta time for one axis.
**
** If the ray direction is zero, a very large value
** is used to avoid division by zero and keep
** the DDA comparison valid.
*/
static double	cal_delta_time_comp(const double ray_comp)
{
	if (ray_comp == 0.0)
		return (1e30);
	return (fabs(1.0 / ray_comp));
}

void	set_delta_time(t_dda *d, const t_vector raydir)
{
	d->delta_time.x = cal_delta_time_comp(raydir.x);
	d->delta_time.y = cal_delta_time_comp(raydir.y);
}
