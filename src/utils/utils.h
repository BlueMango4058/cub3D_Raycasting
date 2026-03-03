/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:16:05 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/15 11:28:24 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "types.h"
# include "queue.h"

void	av_validate(int ac, char **av);
void	error_print(char *msg);
char	**ft_split_charset(const char *str, const char *charset);
void	free_map_data(char ***map, size_t height);
void	free_tex_path_data(t_tex_path *tex_path);
void	free_data(t_data *data);
void	free_split(char ***split);
void	free_resources(t_ctx *ctx, int exit_code);
size_t	get_tokens_size(char **tokens);
int		is_player(const char c);
void	print_data(const t_data *data, int flag);
void	free_mlx(t_ctx *ctx);
void	print_error_spot(const t_map *map, size_t y, size_t x, \
							const t_player *p);
char	**map_copy(const t_map *map);
int		rgb_to_int(const t_rgb color);

#endif
