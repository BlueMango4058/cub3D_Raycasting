/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:52:34 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 17:49:35 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <aio.h>
# define W_WIDTH 800
# define W_HEIGHT 600

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_tex_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_tex_path;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_color
{
	t_rgb	f_color;
	t_rgb	c_color;
}	t_color;

/*
** Map parsing state.
**
** Used to detect invalid map structure such as
** disconnected maps or trailing empty lines.
*/
typedef enum e_map_state
{
	MAP_NOT_STARTED,
	MAP_IN_PROGRESS,
	MAP_FINISHED
}	t_map_state;

/*
** Map data container.
**
** map_data   : raw map lines
** map_height : number of map rows
** max_width  : maximum row width
** capacity   : allocated row capacity
** map_state  : current parsing state
*/
typedef struct s_map
{
	char		**map_data;
	size_t		map_height;
	size_t		max_width;
	size_t		capacity;
	t_map_state	map_state;
}	t_map;

/*
** Player state.
**
** start_pos_* : player position in map coordinates(double)
** start_dir   : initial direction character (N, S, E, W)
** p_dir       : normalized direction vector
*/
typedef struct s_player
{
	double		start_pos_x;
	double		start_pos_y;
	char		start_dir;
	t_vector	p_dir;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_tex_path	tex_path;
	t_color		color;
	t_map		map;
	t_player	player;
	t_img		tex[4];
	int			config_marks;
}	t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	screen;
}	t_mlx;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

// Global runtime context.
typedef struct s_ctx
{
	t_data		data;
	t_mlx		mlx;
	t_keys		keys;
	long long	last_time;
}	t_ctx;

/*
** DDA raycasting state.
**
** pos_*        : ray start position
** map_*        : current map grid position
** p_dir        : player direction vector
** ray_dir      : ray direction for current column
** delta_time   : time weight to next grid line on each axis
** side_time    : time weight to next first grid
** step_*       : step direction in grid
** side         : wall hit side (0: x, 1: y)
** wall_depth   : perpendicular wall depth
*/
typedef struct s_dda
{
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	t_vector	p_dir;
	t_vector	ray_dir;
	t_vector	delta_time;
	t_vector	side_time;
	int			step_x;
	int			step_y;
	int			side;
	double		wall_depth;
}	t_dda;

#endif
