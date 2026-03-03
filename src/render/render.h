/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:05:33 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 17:13:21 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"
# include "utils.h"
# include "render.h"
# include "minilibx-linux/mlx.h"

/*
** line_h : height of the wall slice to draw on screen
** start  : starting y coordinate on the window
** end    : ending y coordinate on the window
** tex_x  : x coordinate in the texture
** tex    : pointer to the selected wall texture
*/
typedef struct s_line_info
{
	int			line_h;
	int			start;
	int			end;
	int			tex_x;
	const t_img	*tex;
}	t_line_info;

void	put_pixel(t_img *s, int x, int y, int color);
void	dda(t_dda *d, const t_data *data, double camera_x);
void	projection(const t_dda *d, const t_data *data, t_img *screen, int x);
void	render_image(t_ctx *ctx);

#endif
