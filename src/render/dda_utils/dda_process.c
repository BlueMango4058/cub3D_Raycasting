/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:42:57 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 16:04:21 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/*
** Runs the DDA stepping loop.
**
** Repeats stepping the ray to the next grid cell
** by comparing side times on x and y.
** Stops when the ray goes out of the map
** or hits a wall tile.
*/
void	dda_process(t_dda *d, const t_data *data)
{
	while (1)
	{
		if (d->side_time.x < d->side_time.y)
		{
			d->side_time.x += d->delta_time.x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_time.y += d->delta_time.y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->map_x < 0 || d->map_y < 0
			|| (size_t)d->map_y >= data->map.map_height
			|| (size_t)d->map_x >= data->map.max_width)
			break ;
		if (data->map.map_data[d->map_y][d->map_x] == '1')
			break ;
	}
}
