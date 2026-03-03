/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:23:56 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 12:04:48 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "minilibx-linux/mlx.h"
#include "utils.h"

static int	load_texture(t_mlx *mlx, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, \
									&tex->width, &tex->height);
	if (!tex->img)
	{
		error_print("xpm img create fail");
		return (0);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, \
									&tex->line_len, &tex->endian);
	if (!tex->addr)
	{
		error_print("mlx get addr fail");
		mlx_destroy_image(mlx->mlx_ptr, tex->img);
		tex->img = NULL;
		return (0);
	}
	return (1);
}

int	setup_texture(t_ctx *ctx)
{
	if (!load_texture(&ctx->mlx, &ctx->data.tex[0], ctx->data.tex_path.no))
		return (0);
	if (!load_texture(&ctx->mlx, &ctx->data.tex[1], ctx->data.tex_path.so))
		return (0);
	if (!load_texture(&ctx->mlx, &ctx->data.tex[2], ctx->data.tex_path.we))
		return (0);
	if (!load_texture(&ctx->mlx, &ctx->data.tex[3], ctx->data.tex_path.ea))
		return (0);
	return (1);
}
