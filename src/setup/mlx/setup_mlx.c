/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:56:30 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/29 12:28:02 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdio.h>
#include "minilibx-linux/mlx.h"

int	setup_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		perror("Error\nmlx_init failed ");
		return (0);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, "cub3D");
	if (!mlx->win_ptr)
	{
		perror("Error\nmlx_new_window_failed ");
		return (0);
	}
	mlx->screen.img = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!mlx->screen.img)
		return (0);
	mlx->screen.addr = mlx_get_data_addr(mlx->screen.img, &mlx->screen.bpp,
			&mlx->screen.line_len, &mlx->screen.endian);
	if (!mlx->screen.addr)
		return (0);
	return (1);
}
