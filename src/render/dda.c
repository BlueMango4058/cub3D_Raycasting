/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:37:44 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:51:29 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_utils.h"
#include "utils.h"

static void	init_dda(t_dda *d, const t_player p)
{
	ft_memset(d, 0, sizeof(*d));
	d->map_x = (int)p.start_pos_x;
	d->map_y = (int)p.start_pos_y;
	d->pos_x = p.start_pos_x;
	d->pos_y = p.start_pos_y;
	d->p_dir = p.p_dir;
}

/*
** Runs one full DDA pipeline for a single ray.
**
** Initializes ray data from the player,
** sets ray direction and timing values,
** and runs the DDA loop to get wall depth.
*/
void	dda(t_dda *d, const t_data *data, double camera_x)
{
	init_dda(d, data->player);
	set_raydir(d, camera_x);
	set_delta_time(d, d->ray_dir);
	set_step_and_side_time(d, d->ray_dir);
	dda_process(d, data);
	set_wall_depth(d);
}
