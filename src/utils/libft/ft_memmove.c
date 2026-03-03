/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:08:27 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/01 16:08:28 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (ptr_dest < ptr_src)
	{
		i = 0;
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			ptr_dest[i] = ptr_src[i];
		}
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char src1[20] = "123456789";
	char src2[20] = "123456789";
	ft_memmove(src1, src1+1, 15);
	printf("%s\n", src1);

	memmove(src2, src2+1, 15);
	printf("%s\n", src2);
	return (0);
}*/
