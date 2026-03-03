/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:08:00 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 17:11:05 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include <sys/time.h>
#include "render.h"

/*
** Checks whether the player can move to the given position.
**
** Uses a circular collision radius to prevent clipping walls.
** Validates map bounds and ensures all sampled points are walkable.
*/
static int	is_walkable(t_ctx *ctx, double x, double y)
{
	t_map	*map;
	double	r;

	map = &ctx->data.map;
	r = PLAYER_RADIUS;
	if (y < 0 || x < 0 || y >= map->map_height)
		return (0);
	if (x >= (double)ft_strlen(map->map_data[(int)y]))
		return (0);
	if (map->map_data[(int)y][(int)x] != '0')
		return (0);
	if (map->map_data[(int)(y + r)][(int)x] != '0' || \
		map->map_data[(int)(y - r)][(int)x] != '0' || \
		map->map_data[(int)y][(int)(x + r)] != '0' || \
		map->map_data[(int)y][(int)(x - r)] != '0')
		return (0);
	return (1);
}

/*
** Moves the player with collision handling.
**
** Calculates the intended movement using the given step function,
** applies collision checks with a fallback factor,
** and resolves movement separately on each axis.
*/
static void	move_player(t_ctx *ctx, void (*step)(t_player *, double), \
						double spd)
{
	t_player	next_p;
	double		dx;
	double		dy;
	double		f;

	next_p = ctx->data.player;
	step(&next_p, spd);
	dx = next_p.start_pos_x - ctx->data.player.start_pos_x;
	dy = next_p.start_pos_y - ctx->data.player.start_pos_y;
	f = 1.0;
	if (!is_walkable(ctx, ctx->data.player.start_pos_x + dx, \
						ctx->data.player.start_pos_y + dy))
		f = 0.5;
	if (is_walkable(ctx, ctx->data.player.start_pos_x + (dx * f), \
						ctx->data.player.start_pos_y))
		ctx->data.player.start_pos_x += (dx * f);
	if (is_walkable(ctx, ctx->data.player.start_pos_x, \
						ctx->data.player.start_pos_y + (dy * f)))
		ctx->data.player.start_pos_y += (dy * f);
}

/*
** Updates player movement and rotation based on key states.
**
** Returns 1 if any movement occurred, otherwise 0.
*/
static int	update_player(t_ctx *c)
{
	int	m;

	m = (c->keys.w || c->keys.s || c->keys.a || c->keys.d \
		|| c->keys.left || c->keys.right);
	if (!m)
		return (0);
	if (c->keys.w)
		move_player(c, step_forward, MOVE_SPEED);
	if (c->keys.s)
		move_player(c, step_backward, MOVE_SPEED);
	if (c->keys.a)
		move_player(c, step_left, MOVE_SPEED);
	if (c->keys.d)
		move_player(c, step_right, MOVE_SPEED);
	if (c->keys.left)
		rotate_left(&c->data.player, ROTATE_SPEED);
	if (c->keys.right)
		rotate_right(&c->data.player, ROTATE_SPEED);
	return (1);
}

/*
** Main loop executed each frame.
**
** Limits updates to approximately 60 FPS,
** updates player state,
** and triggers rendering only when movement occurs.
*/
int	main_loop(t_ctx *ctx)
{
	struct timeval	tv;
	long long		now;

	gettimeofday(&tv, NULL);
	now = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (now - ctx->last_time < 16)
		return (0);
	ctx->last_time = now;
	if (update_player(ctx))
		render_image(ctx);
	return (0);
}
