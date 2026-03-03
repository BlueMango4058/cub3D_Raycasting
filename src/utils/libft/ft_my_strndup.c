/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_strndup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:55:39 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/10 10:17:14 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_my_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	result = (char *)malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
