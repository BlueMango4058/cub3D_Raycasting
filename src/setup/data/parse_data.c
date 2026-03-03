/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:03:01 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:14:17 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_data.h"
#include <fcntl.h>
#include <stdio.h>
#include "utils.h"

/*
** Reads the configuration file line by line and dispatches each line
** to the appropriate parser (config or map).
** Returns 1 on success, 0 on error.
*/
static int	parse_config_and_map(int fd, t_data *data)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line)
	{
		ret = dispatch_line(data, line);
		free(line);
		if (ret != 1)
		{
			get_next_line(-1);
			return (0);
		}
		line = get_next_line(fd);
	}
	get_next_line(-1);
	return (1);
}

int	parse_data(t_data *data, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nCannot open map file ");
		return (0);
	}
	if (parse_config_and_map(fd, data) == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
