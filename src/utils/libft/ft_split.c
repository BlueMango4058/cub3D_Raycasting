/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:57:04 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/09 16:39:03 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		s++;
	}
	return (count);
}

static void	*free_all(char **result, size_t i)
{
	while (i--)
		free(result[i]);
	free(result);
	return (NULL);
}

static void	put_words(char const *s, char c, char **result)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			result[i] = (char *)malloc(len + 1);
			if (!result[i])
			{
				free_all(result, i);
				return ;
			}
			ft_strlcpy(result[i], s, len + 1);
			s += len;
			i++;
		}
	}
	result[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	put_words(s, c, result);
	return (result);
}
