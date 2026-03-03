/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:27:15 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 12:11:39 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "setup_data.h"
#include <stdio.h>

int	padding_map(t_map *map, t_player *player)
{
	char	**padding;
	size_t	new_height;
	size_t	new_width;

	new_height = map->map_height + 2;
	new_width = map->max_width + 2;
	padding = (char **)malloc(sizeof(char *) * (new_height + 1));
	if (!padding)
	{
		perror("Error\nmalloc fail ");
		return (0);
	}
	if (!create_and_check_padded_rows(padding, new_height, new_width))
		return (0);
	if (!copy_and_pad_data(map, padding, new_width))
		return (0);
	update_map_and_player(map, player, padding);
	return (1);
}
