/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:12:05 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/02 14:32:05 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_data.h"
#include "utils.h"

static void	set_player_info(t_player *player, char **map, size_t x, size_t y)
{
	player->start_dir = map[y][x];
	player->start_pos_x = (double)x + 0.5;
	player->start_pos_y = (double)y + 0.5;
}

int	check_player_and_update(char **map, t_player *player)
{
	size_t	x;
	size_t	y;
	int		player_exist;

	player_exist = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
			{
				if (player_exist)
					return (0);
				set_player_info(player, map, x, y);
				player_exist = 1;
			}
			x++;
		}
		y++;
	}
	if (!player_exist)
		return (0);
	return (1);
}

int	static_validate(t_map *map, t_player *player, int marks)
{
	if (!is_all_flags_set(marks))
	{
		error_print("config data is not fully filled in.");
		return (0);
	}
	if (map->map_height == 0 || !map->map_data)
	{
		error_print("map is missing");
		return (0);
	}
	if (!check_player_and_update(map->map_data, player))
	{
		error_print("Invalid player count (must be exactly 1)");
		return (0);
	}
	return (1);
}
