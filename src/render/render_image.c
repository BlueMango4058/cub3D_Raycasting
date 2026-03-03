/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:32:02 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:45:41 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	check_render_condition(t_mlx *mlx)
{
	if (!mlx->mlx_ptr || !mlx->win_ptr || !mlx->screen.img)
	{
		error_print("Rendering condition fail");
		return (0);
	}
	return (1);
}

static void	cast_background(const t_color color, t_mlx *mlx)
{
	int	ceil_color;
	int	floor_color;
	int	y;
	int	x;
	int	row_color;

	ceil_color = rgb_to_int(color.c_color);
	floor_color = rgb_to_int(color.f_color);
	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			if (y < W_HEIGHT / 2)
				row_color = ceil_color;
			else
				row_color = floor_color;
			put_pixel(&mlx->screen, x, y, row_color);
			x++;
		}
		y++;
	}
}

/*
** Casts one ray per screen column.
** camera_x is mapped to the range [-1, 1),
** not exactly [-1, 1], because x iterates
** from 0 to W_WIDTH - 1.
*/
static void	raycast_wall(const t_data *data, t_img *screen)
{
	int		x;
	double	camera_x;
	t_dda	d;

	x = 0;
	while (x < W_WIDTH)
	{
		camera_x = 2.0 * x / (double)W_WIDTH - 1.0;
		dda(&d, data, camera_x);
		projection(&d, data, screen, x);
		x++;
	}
}

static void	raycasting(const t_data *data, t_mlx *mlx)
{
	cast_background(data->color, mlx);
	raycast_wall(data, &mlx->screen);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->screen.img, 0, 0);
}

void	render_image(t_ctx *ctx)
{
	const t_data	*data;
	t_mlx			*mlx;

	data = &ctx->data;
	mlx = &ctx->mlx;
	if (!check_render_condition(mlx))
		free_resources(ctx, 1);
	raycasting(data, mlx);
}
