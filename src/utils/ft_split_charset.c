/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:20:23 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/12 17:13:01 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	result_size(const char *str, const char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_charset(*str, charset))
		{
			in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		str++;
	}
	return (count);
}

static void	ft_put(char **result, const char *start, int word_len, int *i)
{
	int	j;

	j = 0;
	if (word_len > 0)
	{
		result[*i] = (char *)malloc(word_len + 1);
		if (!result[*i])
			return ;
		while (j < word_len)
		{
			result[*i][j] = start[j];
			j++;
		}
		result[*i][j] = '\0';
	}
}

static void	put_word(const char *str, const char *charset, char **result)
{
	const char	*start;
	int			word_len;
	int			i;

	i = 0;
	while (*str)
	{
		if (is_charset(*str, charset))
			str++;
		else
		{
			start = str;
			word_len = 0;
			while (*str && !is_charset(*str, charset))
			{
				str++;
				word_len++;
			}
			ft_put(result, start, word_len, &i);
			i++;
		}
	}
	result[i] = NULL;
}

char	**ft_split_charset(const char *str, const char *charset)
{
	char	**result;
	int		r_size;

	if (!str)
		return (NULL);
	r_size = result_size(str, charset);
	result = (char **)malloc(sizeof(char *) * (r_size + 1));
	if (!result)
		return (NULL);
	put_word(str, charset, result);
	return (result);
}
