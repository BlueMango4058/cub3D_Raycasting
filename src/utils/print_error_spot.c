/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_spot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:09:26 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/15 11:37:09 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdio.h>
#include "utils.h"

static void	print_x_axis(const t_map *map, size_t x)
{
	size_t	j;

	printf("   ");
	j = x - 1;
	while (j <= x + 1)
	{
		if (j < map->max_width)
			printf(" %lu ", j);
		j++;
	}
	printf("\n   ----------\n");
}

static char	get_display_char(const t_map *map, \
							size_t y, size_t x, \
							const t_player *p)
{
	if ((size_t)p->start_pos_x == x && (size_t)p->start_pos_y == y)
		return (p->start_dir);
	return (map->map_data[y][x]);
}

static void	print_map_rows(const t_map *map, \
							size_t y, size_t x, \
							const t_player *p)
{
	size_t	i;
	size_t	j;

	i = y - 1;
	while (i <= y + 1 && i < map->map_height)
	{
		printf("%lu |", i);
		j = x - 1;
		while (j <= x + 1 && j < map->max_width)
		{
			if (i == y && j == x)
				printf("[%c]", get_display_char(map, i, j, p));
			else
				printf(" %c ", get_display_char(map, i, j, p));
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_error_spot(const t_map *map, \
							size_t y, size_t x, \
							const t_player *p)
{
	if (x == 0 || y == 0)
	{
		error_print("Unexpecte map error pirnt");
		return ;
	}
	printf("Error\nMap is not close\n");
	printf("--- Error Spot Visual (3x3) ---\n");
	print_x_axis(map, x);
	print_map_rows(map, y, x, p);
	printf("-------------------------------\n");
}
