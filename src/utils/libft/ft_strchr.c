/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:56:51 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/02 12:56:52 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
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

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char *s = "AAAABAA";
	int c = '\0';

	printf("ft : %p\n", ft_strchr(s,c));
	printf("origin : %p\n", strchr(s,c));
	return (0);
}*/
