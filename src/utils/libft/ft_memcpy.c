/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:39:20 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/01 15:39:21 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*src_value;

	ptr = (unsigned char *)dest;
	src_value = (const unsigned char *)src;
	while (n--)
		*ptr++ = *src_value++;
	return (dest);
}
