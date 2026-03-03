/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:06:48 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/03 12:34:38 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
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

//✔ 표준 strdup은 OS마다 동작이 다를 수 있지만, 대부분 NULL 입력 시 크래시 발생.
//✔ ft_strlen(NULL)이 세그폴트를 발생시키므로, 결과적으로 동일한 동작을 함.