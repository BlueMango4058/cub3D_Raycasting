/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:36:09 by dsagong           #+#    #+#             */
/*   Updated: 2025/11/19 16:15:59 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_rest(int fd, char *rest)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	read_value;
	char	*temp;

	read_value = 1;
	while (!gnl_ft_strchr(rest, '\n') && read_value != 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1)
		{
			free(rest);
			return (NULL);
		}
		buf[read_value] = '\0';
		temp = gnl_ft_strjoin(rest, buf);
		free(rest);
		rest = temp;
		if (!rest)
			return (NULL);
	}
	return (rest);
}

static char	*extract_line(char *rest)
{
	if (!rest || !*rest)
		return (NULL);
	return (make_line(rest));
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = read_to_rest(fd, rest);
	if (!rest)
		return (NULL);
	line = extract_line(rest);
	rest = realloc_rest(rest);
	return (line);
}
