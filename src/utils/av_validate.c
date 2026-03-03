/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:55:43 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/23 11:23:25 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	filename_check(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strcmp(filename + (len - 4), ".cub") != 0)
		return (0);
	return (1);
}

//argument validate
void	av_validate(int ac, char **av)
{
	if (ac != 2)
	{
		error_print("Usage: ./cube3D path/map.cub");
		exit(1);
	}
	if (!av[1] || !av[1][0])
	{
		error_print("Need map filename");
		exit(1);
	}
	if (filename_check(av[1]) != 1)
	{
		error_print("Map file must end with .cub");
		exit(1);
	}
}
