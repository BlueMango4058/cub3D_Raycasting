/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:11:49 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 15:29:33 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "setup_data.h"
#include "utils.h"
#include <stdio.h>

static int	count_comma(const char *rgb)
{
	int	count;

	count = 0;
	while (*rgb)
	{
		if (*rgb == ',')
			count++;
		rgb++;
	}
	return (count);
}

/*
** Validates a single RGB color value (0–255, no leading zeros).
*/
static int	color_value_check(char *color)
{
	size_t	len;
	size_t	i;

	if (!color || !*color)
		return (0);
	len = ft_strlen(color);
	if (len == 0 || len > 3)
		return (0);
	if (len > 1 && color[0] == '0')
		return (0);
	i = 0;
	while (i < len)
	{
		if (!ft_isdigit(color[i]))
			return (0);
		i++;
	}
	if (len == 3 && ft_strcmp(color, "255") > 0)
		return (0);
	return (1);
}

/*
** Validates RGB string format.
** - Must contain exactly two commas (R,G,B)
** - Must be split into exactly three numeric values
** - Each value must be within the valid color range (0–255)
*/
static int	validate_rgb_line(char **colors, const char *rgb)
{
	size_t	i;

	if (!colors || !*colors)
		return (0);
	if (count_comma(rgb) != 2)
		return (0);
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	while (colors[i])
	{
		if (color_value_check(colors[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	insert_rgb_value(t_color *color, t_data_type type, char **colors)
{
	if (type == T_F_DATA)
	{
		color->f_color.r = ft_atoi(colors[0]);
		color->f_color.g = ft_atoi(colors[1]);
		color->f_color.b = ft_atoi(colors[2]);
	}
	if (type == T_C_DATA)
	{
		color->c_color.r = ft_atoi(colors[0]);
		color->c_color.g = ft_atoi(colors[1]);
		color->c_color.b = ft_atoi(colors[2]);
	}
}

/*
** Parses, validates, and stores RGB color configuration.
*/
int	setup_config_color(t_color *color, t_data_type type, const char *rgb)
{
	char	**colors;

	colors = ft_split(rgb, ',');
	if (!colors)
	{
		perror("Error\nSplit fail ");
		return (0);
	}
	if (validate_rgb_line(colors, rgb) == 0)
	{
		error_print("RGB value was wrong format (0 ~ 255,0 ~ 255,0 ~ 255)");
		free_split(&colors);
		return (0);
	}
	insert_rgb_value(color, type, colors);
	free_split(&colors);
	return (1);
}
