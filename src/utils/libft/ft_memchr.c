/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:20:00 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/04 12:02:07 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		value;

	ptr = (const unsigned char *)s;
	value = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == value)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
