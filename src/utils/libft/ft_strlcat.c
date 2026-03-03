/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:49:09 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/02 10:49:10 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	char	*m_dst;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	m_dst = dst + dst_len;
	while (src[i] && i < size - dst_len - 1)
	{
		m_dst[i] = src[i];
		i++;
	}
	m_dst[i] = '\0';
	return (dst_len + src_len);
}
