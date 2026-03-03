/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:59:36 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 16:43:24 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "types.h"
# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_A			97
# define KEY_D			100
# define KEY_W			119
# define KEY_S			115
# define PLAYER_RADIUS	0.06
# define MOVE_SPEED		0.05
# define ROTATE_SPEED	0.05

//event.c
void	hook_events(t_ctx *ctx);

//step.c
void	step_forward(t_player *p, double delta);
void	step_backward(t_player *p, double delta);
void	step_left(t_player *p, double delta);
void	step_right(t_player *p, double delta);

//rotate.c
void	rotate_left(t_player *p, double rot);
void	rotate_right(t_player *p, double rot);

//movement.c
int		main_loop(t_ctx *ctx);

#endif
