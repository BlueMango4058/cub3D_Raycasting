/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:21:20 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 17:25:38 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "setup_data.h"
#include "utils.h"

static int	is_color(t_data_type type)
{
	return (type == T_F_DATA || type == T_C_DATA);
}

static int	config_data_validate_and_copy(t_data *data, t_data_type type,
									char **tokens)
{
	if (is_color(type))
	{
		if (setup_config_color(&data->color, type, tokens[1]) == 0)
			return (0);
		return (1);
	}
	else
	{
		if (setup_config_texture(&data->tex_path, type, tokens[1]) == 0)
			return (0);
		return (1);
	}
	return (0);
}

/*
** Validates and stores a single configuration entry.
** Ensures uniqueness, correct format, and updates the config state.
*/
int	setup_config_data(t_data *data, t_data_type type, char **tokens)
{
	if (data->config_marks & (1 << type))
	{
		error_print("The same type cannot appear more than once");
		return (0);
	}
	if (get_tokens_size(tokens) != 2)
	{
		error_print("Config format error "
			"(Type <space> value <- value must not contain spaces)");
		return (0);
	}
	if (config_data_validate_and_copy(data, type, tokens) == 0)
		return (0);
	data->config_marks |= (1 << type);
	return (1);
}
