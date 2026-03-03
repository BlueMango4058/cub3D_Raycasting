/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:47:41 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 16:08:02 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

#define NO 0
#define SO 1
#define WE 2
#define EA 3

static int	get_pixel_from_texture(const t_img *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

static int	get_tex_dir(const t_dda *d)
{
	if (d->side == 0)
	{
		if (d->ray_dir.x > 0)
			return (EA);
		return (WE);
	}
	if (d->ray_dir.y > 0)
		return (SO);
	return (NO);
}

/*
** Calculates the x coordinate in the wall texture.
**
** Finds the exact hit position on the wall,
** converts it to a texture x index,
** and flips it when needed to keep orientation correct.
*/
static int	calculate_tex_x(const t_dda *d, const t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (d->side == 0)
		wall_x = d->pos_y + d->wall_depth * d->ray_dir.y;
	else
		wall_x = d->pos_x + d->wall_depth * d->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((d->side == 0 && d->ray_dir.x < 0) || \
		(d->side == 1 && d->ray_dir.y > 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

/*
** Draws a vertical textured line on the screen.
**
** Maps texture y-coordinates to screen pixels
** based on the projected wall height.
*/
static void	draw_textured_line(t_line_info *info, t_img *screen, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		color;
	int		tex_y;

	step = (double)info->tex->height / (double)info->line_h;
	tex_pos = (info->start - W_HEIGHT / 2 + info->line_h / 2) * step;
	y = info->start;
	while (y <= info->end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= info->tex->height)
			tex_y = info->tex->height - 1;
		tex_pos += step;
		color = get_pixel_from_texture(info->tex, info->tex_x, tex_y);
		put_pixel(screen, x, y, color);
		y++;
	}
}

/*
** Projects a single wall slice onto the screen.
**
** Uses the wall depth from DDA to compute
** vertical line height, selects the correct texture,
** and draws the textured column at screen x.
*/
void	projection(const t_dda *d, const t_data *data, t_img *screen, int x)
{
	t_line_info	li;

	li.line_h = (int)((double)W_HEIGHT / d->wall_depth);
	li.start = -li.line_h / 2 + W_HEIGHT / 2;
	if (li.start < 0)
		li.start = 0;
	li.end = li.line_h / 2 + W_HEIGHT / 2;
	if (li.end >= W_HEIGHT)
		li.end = W_HEIGHT - 1;
	li.tex = &data->tex[get_tex_dir(d)];
	li.tex_x = calculate_tex_x(d, li.tex);
	draw_textured_line(&li, screen, x);
}
