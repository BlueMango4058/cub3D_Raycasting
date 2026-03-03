/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:26:31 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 12:04:56 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

void	free_screen_image(t_mlx *mlx)
{
	if (mlx->mlx_ptr && mlx->screen.img)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->screen.img);
		mlx->screen.img = NULL;
	}
}

void	free_textures(t_mlx *mlx, t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mlx->mlx_ptr && data->tex[i].img)
		{
			mlx_destroy_image(mlx->mlx_ptr, data->tex[i].img);
			data->tex[i].img = NULL;
		}
		i++;
	}
}

void	free_window(t_mlx *mlx)
{
	if (mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
	}
}

void	free_mlx_ptr(t_mlx *mlx)
{
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
}

void	free_mlx(t_ctx *ctx)
{
	t_mlx	*mlx;

	mlx = &ctx->mlx;
	if (!mlx)
		return ;
	free_screen_image(mlx);
	free_textures(mlx, &ctx->data);
	free_window(mlx);
	free_mlx_ptr(mlx);
}
