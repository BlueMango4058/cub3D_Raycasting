/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:25:14 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 12:19:53 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdio.h>

static void	print_texture_paths(const t_data *data)
{
	printf("Texture Paths:\n");
	if (data->tex_path.no)
		printf("- NO: %s\n", data->tex_path.no);
	if (data->tex_path.so)
		printf("- SO: %s\n", data->tex_path.so);
	if (data->tex_path.we)
		printf("- WE: %s\n", data->tex_path.we);
	if (data->tex_path.ea)
		printf("- EA: %s\n", data->tex_path.ea);
}

static void	print_colors(const t_data *data)
{
	printf("\nColors:\n");
	printf("- F: R=%d G=%d B=%d\n", \
		data->color.f_color.r, data->color.f_color.g, data->color.f_color.b);
	printf("- C: R=%d G=%d B=%d\n", \
		data->color.c_color.r, data->color.c_color.g, data->color.c_color.b);
}

static void	print_player_info(const t_data *data)
{
	printf("\nPalyer:\n");
	printf("- Start dir : %c\n", data->player.start_dir);
	printf("- Start pos X : %f\n", data->player.start_pos_x);
	printf("- Start pos Y : %f\n", data->player.start_pos_y);
}

static void	print_map_data(const t_data *data)
{
	size_t	i;

	printf("\nMap:\n");
	printf("- Map height = %zu\n", data->map.map_height);
	printf("- Map max_width = %zu\n", data->map.max_width);
	printf("- Map data:\n");
	if (!data->map.map_data)
	{
		printf("(null)\n");
		return ;
	}
	i = 0;
	while (i < data->map.map_height)
	{
		if (data->map.map_data[i])
			printf("%s\n", data->map.map_data[i]);
		i++;
	}
}

void	print_data(const t_data *data)
{
	if (!data)
		return ;
	print_texture_paths(data);
	print_colors(data);
	print_player_info(data);
	print_map_data(data);
}
