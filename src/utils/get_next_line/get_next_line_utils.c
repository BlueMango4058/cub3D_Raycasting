/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:04:38 by dsagong           #+#    #+#             */
/*   Updated: 2025/11/19 13:31:53 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	result_index;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (gnl_ft_strdup(s2));
	len1 = gnl_ft_strchr(s1, '\0') - s1;
	len2 = gnl_ft_strchr(s2, '\0') - s2;
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	result_index = 0;
	while (*s1)
		result[result_index++] = *s1++;
	while (*s2)
		result[result_index++] = *s2++;
	result[result_index] = '\0';
	return (result);
}

char	*gnl_ft_strdup(const char *s)
{
	char	*result;
	size_t	i;
	size_t	len;

	len = gnl_ft_strchr(s, '\0') - s;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*make_line(char *rest)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!rest || rest[0] == '\0')
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = rest[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*realloc_rest(char *rest)
{
	char	*newline_ptr;
	char	*new_rest;

	if (!rest || rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	newline_ptr = gnl_ft_strchr(rest, '\n');
	if (!newline_ptr)
		return (rest);
	new_rest = gnl_ft_strdup(newline_ptr + 1);
	free(rest);
	return (new_rest);
}
