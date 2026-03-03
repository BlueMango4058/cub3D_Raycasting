/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:44:02 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 13:05:42 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "math.h"

void	rotate_left(t_player *p, double rot)
{
	double	old_x;
	double	c;
	double	s;

	c = cos(-rot);
	s = sin(-rot);
	old_x = p->p_dir.x;
	p->p_dir.x = p->p_dir.x * c - p->p_dir.y * s;
	p->p_dir.y = old_x * s + p->p_dir.y * c;
}

void	rotate_right(t_player *p, double rot)
{
	double	old_x;
	double	c;
	double	s;

	c = cos(rot);
	s = sin(rot);
	old_x = p->p_dir.x;
	p->p_dir.x = p->p_dir.x * c - p->p_dir.y * s;
	p->p_dir.y = old_x * s + p->p_dir.y * c;
}
