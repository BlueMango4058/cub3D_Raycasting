/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:18:14 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/23 19:18:25 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**map_copy(const t_map *map)
{
	char	**copy_map;
	size_t	i;

	copy_map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (i < map->map_height)
	{
		copy_map[i] = ft_strdup(map->map_data[i]);
		if (!copy_map)
		{
			free_map_data(&copy_map, i);
			return (NULL);
		}
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}
