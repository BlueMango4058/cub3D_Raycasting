/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:49:39 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:21:05 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "setup_data.h"
#include <stdio.h>

static t_data_type	get_type(char **tokens)
{
	if (!tokens[0])
		return (T_EMPTY_LINE);
	if (ft_strcmp(tokens[0], "NO") == 0)
		return (T_NO_DATA);
	if (ft_strcmp(tokens[0], "SO") == 0)
		return (T_SO_DATA);
	if (ft_strcmp(tokens[0], "WE") == 0)
		return (T_WE_DATA);
	if (ft_strcmp(tokens[0], "EA") == 0)
		return (T_EA_DATA);
	if (ft_strcmp(tokens[0], "F") == 0)
		return (T_F_DATA);
	if (ft_strcmp(tokens[0], "C") == 0)
		return (T_C_DATA);
	return (T_MAP_DATA);
}

/*
** Handles empty lines during parsing.
** An empty line after map start marks the end of the map.
*/
static int	handle_empty_line(t_data *data, char **tokens)
{
	free_split(&tokens);
	if (data->map.map_state == MAP_IN_PROGRESS)
		data->map.map_state = MAP_FINISHED;
	return (1);
}

/*
** Handles a map line during parsing.
** Ensures that all config data is set before the map starts and
** enforces map continuity using a map state machine.
*/
static int	handle_map_line(t_data *data, char **tokens,
							const char *line, int full)
{
	free_split(&tokens);
	if (!full)
	{
		error_print("Config data incomplete before map.");
		return (0);
	}
	if (data->map.map_state == MAP_FINISHED)
	{
		error_print("Disconnected map detected");
		return (0);
	}
	data->map.map_state = MAP_IN_PROGRESS;
	return (setup_map_data(data, line));
}

static int	handle_config_line(t_data *data, t_data_type type, char **tokens)
{
	int	status;

	status = setup_config_data(data, type, tokens);
	free_split(&tokens);
	return (status);
}

/*
** Splits a line into tokens, determines its type (config, map, or empty),
** and dispatches it to the corresponding handler.
** Returns 1 on success, 0 on error.
*/
int	dispatch_line(t_data *data, const char *line)
{
	char		**tokens;
	t_data_type	type;
	int			full;

	tokens = ft_split_charset(line, " \t");
	if (!tokens)
	{
		perror("Error\nmalloc fail ");
		return (0);
	}
	full = is_all_flags_set(data->config_marks);
	type = get_type(tokens);
	if (type == T_EMPTY_LINE)
		return (handle_empty_line(data, tokens));
	if (type == T_MAP_DATA)
		return (handle_map_line(data, tokens, line, full));
	return (handle_config_line(data, type, tokens));
}
