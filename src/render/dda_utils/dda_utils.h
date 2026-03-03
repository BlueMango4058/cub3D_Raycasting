/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:01 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 17:13:34 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_UTILS_H
# define DDA_UTILS_H
# include "types.h"

void	set_raydir(t_dda *d, const double camera_x);
void	set_delta_time(t_dda *d, const t_vector raydir);
void	set_step_and_side_time(t_dda *d, const t_vector ray);
void	dda_process(t_dda *d, const t_data *data);
void	set_wall_depth(t_dda *d);

#endif
