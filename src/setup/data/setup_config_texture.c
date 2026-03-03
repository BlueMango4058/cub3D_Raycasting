/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:42:03 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:31:01 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "setup_data.h"
#include <fcntl.h>
#include "utils.h"
#include <stdio.h>

/*
** Validates texture path from config.
** - Must end with ".xpm"
** - File must be accessible at parse time to prevent runtime errors
*/
static int	validate_config_path(const char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(path + (len -4), ".xpm") != 0)
	{
		error_print("Texture file must end with .xpm");
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nTexture file cannot be opened ");
		return (0);
	}
	close(fd);
	return (1);
}

static char	**config_location(t_tex_path *tex_path, t_data_type type)
{
	if (type == T_NO_DATA)
		return (&tex_path->no);
	if (type == T_SO_DATA)
		return (&tex_path->so);
	if (type == T_EA_DATA)
		return (&tex_path->ea);
	if (type == T_WE_DATA)
		return (&tex_path->we);
	return (NULL);
}

int	setup_config_texture(t_tex_path *tex_path, t_data_type type, \
						const char *path)
{
	char	**loc;
	char	*tmp;

	if (validate_config_path(path) == 0)
		return (0);
	loc = config_location(tex_path, type);
	if (!loc)
	{
		error_print("No texture type");
		return (0);
	}
	tmp = ft_strdup(path);
	if (!tmp)
	{
		perror("Error\nmalloc fail ");
		return (0);
	}
	*loc = tmp;
	return (1);
}
