/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:25:30 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/05 11:25:50 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	put_pixel(t_img *s, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	dst = s->addr + (y * s->line_len + x * (s->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}
