/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:52:32 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:24:09 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

static int	map_element(const char c)
{
	return (c == ' ' || c == '1' || c == '0' || \
			c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

static int	validate_map_line(const char *line)
{
	while (*line)
	{
		if (!map_element(*line))
			return (0);
		line++;
	}
	return (1);
}

static int	map_expand(t_map *map)
{
	char	**new_map;
	size_t	new_capacity;

	if (map->capacity == 0)
		new_capacity = 4;
	else
		new_capacity = map->capacity * 2;
	new_map = malloc(sizeof(char *) * (new_capacity + 1));
	if (!new_map)
	{
		perror("Error\nmalloc fail ");
		return (0);
	}
	if (map->map_data)
		ft_memmove(new_map, map->map_data, sizeof(char *) * map->map_height);
	free(map->map_data);
	map->map_data = new_map;
	map->capacity = new_capacity;
	map->map_data[map->map_height] = NULL;
	return (1);
}

static int	map_data_realloc_and_copy(t_map *map, const char *line)
{
	size_t	len;

	if (map->map_height >= map->capacity)
	{
		if (!map_expand(map))
			return (0);
	}
	map->map_data[map->map_height] = ft_strdup(line);
	if (!map->map_data[map->map_height])
	{
		perror("Error\nmalloc fail ");
		return (0);
	}
	len = ft_strlen(line);
	if (map->max_width < len)
		map->max_width = len;
	map->map_height++;
	map->map_data[map->map_height] = NULL;
	return (1);
}

/*
** Validates and stores a single map line.
** Ensures that the line contains only valid map characters
** before appending it to the map data.
*/
int	setup_map_data(t_data *data, const char *line)
{
	if (validate_map_line(line) == 0)
	{
		error_print("Map data is only filled in ' ',1,0,N,E,W,S");
		return (0);
	}
	if (!map_data_realloc_and_copy(&data->map, line))
		return (0);
	return (1);
}
