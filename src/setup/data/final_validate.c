/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:09:48 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/15 11:35:39 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_data.h"

int	final_validate(t_data *data)
{
	if (static_validate(&data->map, &data->player, data->config_marks) == 0)
		return (0);
	if (padding_map(&data->map, &data->player) == 0)
		return (0);
	if (map_closure_validate(&data->map, &data->player) == 0)
		return (0);
	if (validate_single_map(&data->map) == 0)
		return (0);
	return (1);
}
