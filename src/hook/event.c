/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:00:33 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 16:10:01 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "hook.h"
#include "utils.h"

static int	handle_key_event(int keycode, t_ctx *ctx, int is_press)
{
	if (is_press && keycode == KEY_ESC)
		free_resources(ctx, 0);
	if (keycode == KEY_W)
		ctx->keys.w = is_press;
	if (keycode == KEY_S)
		ctx->keys.s = is_press;
	if (keycode == KEY_A)
		ctx->keys.a = is_press;
	if (keycode == KEY_D)
		ctx->keys.d = is_press;
	if (keycode == KEY_LEFT)
		ctx->keys.left = is_press;
	if (keycode == KEY_RIGHT)
		ctx->keys.right = is_press;
	return (0);
}

static int	handle_key_press(int keycode, t_ctx *ctx)
{
	return (handle_key_event(keycode, ctx, 1));
}

static int	handle_key_release(int keycode, t_ctx *ctx)
{
	return (handle_key_event(keycode, ctx, 0));
}

static int	close_window(t_ctx *ctx)
{
	free_resources(ctx, 0);
	return (0);
}

/*
** Registers all event hooks for user interaction.
**
** - Key press / release events update key states
** - Window close event exits the program safely
** - Loop hook runs the main game update each frame
*/
void	hook_events(t_ctx *ctx)
{
	mlx_hook(ctx->mlx.win_ptr, 2, 1L << 0, handle_key_press, ctx);
	mlx_hook(ctx->mlx.win_ptr, 3, 1L << 1, handle_key_release, ctx);
	mlx_hook(ctx->mlx.win_ptr, 17, 0, close_window, ctx);
	mlx_loop_hook(ctx->mlx.mlx_ptr, main_loop, ctx);
}
