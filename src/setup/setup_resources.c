/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:09:13 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:12:40 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_data.h"
#include "setup_mlx.h"

int	setup_resources(t_ctx *ctx, char *filename)
{
	if (setup_data(&ctx->data, filename) == 0)
		return (0);
	setup_player_dir(&ctx->data.player);
	if (setup_mlx(&ctx->mlx) == 0)
		return (0);
	if (setup_texture(ctx) == 0)
		return (0);
	return (1);
}
