/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:09:07 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/29 12:18:45 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "types.h"

void	free_map_data(char ***map, size_t height)
{
	size_t	i;

	if (!map || !*map)
		return ;
	i = 0;
	while (i < height)
	{
		if ((*map)[i])
			free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

void	free_tex_path_data(t_tex_path *tex_path)
{
	if (!tex_path)
		return ;
	free(tex_path->no);
	free(tex_path->so);
	free(tex_path->we);
	free(tex_path->ea);
	tex_path->no = NULL;
	tex_path->so = NULL;
	tex_path->we = NULL;
	tex_path->ea = NULL;
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_tex_path_data(&data->tex_path);
	free_map_data(&(data->map.map_data), data->map.map_height);
}

void	free_split(char ***split)
{
	size_t	i;

	if (!split || !*split)
		return ;
	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		(*split)[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
}

void	free_resources(t_ctx *ctx, int exit_code)
{
	free_data(&ctx->data);
	free_mlx(ctx);
	exit(exit_code);
}
