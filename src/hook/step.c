/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:54:18 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 13:05:55 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	step_forward(t_player *p, double delta)
{
	p->start_pos_x += p->p_dir.x * delta;
	p->start_pos_y += p->p_dir.y * delta;
}

void	step_backward(t_player *p, double delta)
{
	p->start_pos_x -= p->p_dir.x * delta;
	p->start_pos_y -= p->p_dir.y * delta;
}

void	step_left(t_player *p, double delta)
{
	p->start_pos_x += p->p_dir.y * delta;
	p->start_pos_y += -p->p_dir.x * delta;
}

void	step_right(t_player *p, double delta)
{
	p->start_pos_x += -p->p_dir.y * delta;
	p->start_pos_y += p->p_dir.x * delta;
}
