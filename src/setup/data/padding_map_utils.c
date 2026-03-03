/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:11:12 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 12:12:29 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "setup_data.h"

char	*create_padded_row(size_t width)
{
	char	*row;

	row = (char *)malloc(width + 1);
	if (!row)
		return (NULL);
	ft_memset(row, 'P', width);
	row[width] = '\0';
	return (row);
}

char	*create_map_row(const char *src_line, size_t new_width)
{
	char	*row;
	size_t	i;
	size_t	j;

	row = (char *)malloc(new_width + 1);
	if (!row)
		return (NULL);
	i = 0;
	j = 0;
	row[i++] = 'P';
	while (src_line[j])
	{
		if (src_line[j] == ' ')
			row[i] = 'P';
		else
			row[i] = src_line[j];
		i++;
		j++;
	}
	while (i < new_width)
		row[i++] = 'P';
	row[new_width] = '\0';
	return (row);
}

int	copy_and_pad_data(t_map *map, char **padding, size_t new_width)
{
	size_t	i;

	i = 0;
	while (i < map->map_height)
	{
		padding[i + 1] = create_map_row(map->map_data[i], new_width);
		if (!padding[i + 1])
		{
			free_map_data(&padding, i + 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_and_check_padded_rows(char **padding, \
									size_t new_height, size_t new_width)
{
	padding[0] = create_padded_row(new_width);
	if (!padding[0])
	{
		free(padding);
		return (0);
	}
	padding[new_height - 1] = create_padded_row(new_width);
	if (!padding[new_height - 1])
	{
		free(padding[0]);
		free(padding);
		return (0);
	}
	padding[new_height] = NULL;
	return (1);
}

void	update_map_and_player(t_map *map, t_player *player, \
										char **padding)
{
	free_map_data(&(map->map_data), map->map_height);
	map->map_data = padding;
	map->map_height += 2;
	map->max_width += 2;
	player->start_pos_x += 1.0;
	player->start_pos_y += 1.0;
	map->map_data[(int)player->start_pos_y][(int)player->start_pos_x] = '0';
}
