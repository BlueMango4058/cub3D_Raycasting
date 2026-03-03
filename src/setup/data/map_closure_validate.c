/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closure_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:38:44 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/15 11:16:25 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_data.h"
#include <stdio.h>
#include "utils.h"

static int	check_neighbors(char **padd_map, size_t y, size_t x)
{
	static const int	dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	static const int	dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int					i;
	int					ny;
	int					nx;

	i = 0;
	while (i < 8)
	{
		nx = (int)x + dx[i];
		ny = (int)y + dy[i];
		if (padd_map[ny][nx] == 'P')
			return (0);
		i++;
	}
	return (1);
}

int	map_closure_validate(const t_map *map, const t_player *p)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (y < map->map_height - 1)
	{
		x = 1;
		while (x < map->max_width - 1)
		{
			if (map->map_data[y][x] == '0')
			{
				if (check_neighbors(map->map_data, y, x) == 0)
				{
					print_error_spot(map, y, x, p);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}
