/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_single_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:30:15 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 12:18:42 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include <stdio.h>

static int	find_start_point(char **copy_map, const t_map *map, t_point *start)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->max_width)
		{
			if (copy_map[y][x] != 'P')
			{
				start->x = x;
				start->y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	neighbor_point_enqueue(t_queue *q, char **map_c, \
								t_point curr, const t_map *m)
{
	int					i;
	int					nx;
	int					ny;
	static const int	dy[] = {-1, 0, 1, 0};
	static const int	dx[] = {0, 1, 0, -1};

	i = -1;
	while (++i < 4)
	{
		nx = (int)curr.x + dx[i];
		ny = (int)curr.y + dy[i];
		if (nx >= 0 && nx < (int)m->max_width && \
			ny >= 0 && ny < (int)m->map_height)
		{
			if (map_c[ny][nx] != 'P')
			{
				enqueue(q, (size_t)ny, (size_t)nx);
				map_c[ny][nx] = 'P';
			}
		}
	}
}

static void	bfs(char **copy_map, t_queue *queue, \
				t_point start_p, const t_map *map)
{
	t_point	curr;

	enqueue(queue, start_p.y, start_p.x);
	copy_map[start_p.y][start_p.x] = 'P';
	while (queue->front < queue->rear)
	{
		curr = dequeue(queue);
		neighbor_point_enqueue(queue, copy_map, curr, map);
	}
}

static int	check_remain(char **copy_map, const t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->max_width)
		{
			if (copy_map[y][x] != 'P')
			{
				error_print("Disconnected map detected");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_single_map(const t_map *map)
{
	char	**copy_map;
	t_queue	queue;
	t_point	start;
	int		result;

	result = 0;
	copy_map = map_copy(map);
	if (!copy_map)
		return (0);
	queue_init(&queue, map->max_width, map->map_height);
	if (queue.data)
	{
		if (find_start_point(copy_map, map, &start))
		{
			bfs(copy_map, &queue, start, map);
			if (!check_remain(copy_map, map))
				result = 1;
		}
		free(queue.data);
	}
	free_map_data(&copy_map, map->map_height);
	return (result);
}
