/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:42:44 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 17:22:26 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_DATA_H
# define SETUP_DATA_H

# include "types.h"

//Bitmask flags for checking required config data
# define MARK_NO 1
# define MARK_SO 2
# define MARK_WE 4
# define MARK_EA 8
# define MARK_F 16
# define MARK_C 32

/*
** Data type identifiers used during parsing.
**
** These values represent the kind of line currently being processed,
** such as texture paths, color definitions, map data, or empty lines.
*/
typedef enum e_data_type
{
	T_NO_DATA,
	T_SO_DATA,
	T_WE_DATA,
	T_EA_DATA,
	T_F_DATA,
	T_C_DATA,
	T_MAP_DATA,
	T_EMPTY_LINE
}	t_data_type;

//Data setup & entry points
int		setup_data(t_data *data, const char *filename);
int		parse_data(t_data *data, const char *filename);
int		final_validate(t_data *data);

//dispatch
int		dispatch_line(t_data *data, const char *line);

//Map data setup
int		setup_map_data(t_data *data, const char *line);

//Config data setup
int		setup_config_data(t_data *data, t_data_type type, char **tokens);
int		setup_config_color(t_color *color, t_data_type type, const char *rgb);
int		setup_config_texture(t_tex_path *tex_path, t_data_type type, \
							const char *path);

//Validation
int		static_validate(t_map *map, t_player *player, int marks);
int		map_closure_validate(const t_map *map, const t_player *player);
int		validate_single_map(const t_map *map);

//Padding
int		padding_map(t_map *map, t_player *player);
int		create_and_check_padded_rows(char **padding, \
									size_t new_height, size_t new_width);
int		copy_and_pad_data(t_map *map, char **padding, size_t new_width);
char	*create_padded_row(size_t width);
char	*create_map_row(const char *src_line, size_t new_width);
void	update_map_and_player(t_map *map, t_player *player, char **padding);

//Player setup
void	setup_player_dir(t_player *p);

//Utils
int		is_all_flags_set(int marks);
#endif
