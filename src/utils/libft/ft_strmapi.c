/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:17:39 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/07 16:23:07 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}

/*#include <stdio.h>
//예제 1: 모든 문자를 대문자로 변환 (ft_toupper 비슷)
char	to_upper(unsigned int i, char c)
{
	(void)i; // 인덱스는 사용하지 않음
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

//예제 2: 문자에 인덱스를 더해서 밀어줌
char	shift_char(unsigned int i, char c)
{
	return (c + i);
}

//예제 3: 홀수 인덱스의 문자만 대문자로 변환
char	odd_upper(unsigned int i, char c)
{
	if (i % 2 == 1 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*result;

	// 예제 1
	result = ft_strmapi("hello world", to_upper);
	if (result)
	{
		printf("to_upper     : %s\n", result); // HELLO WORLD
		free(result);
	}

	// 예제 2
	result = ft_strmapi("abcd", shift_char);
	if (result)
	{
		printf("shift_char   : %s\n", result); // aceg
		free(result);
	}

	// 예제 3
	result = ft_strmapi("abcdef", odd_upper);
	if (result)
	{
		printf("odd_upper    : %s\n", result); // aBcDeF
		free(result);
	}

	return (0);
}*/