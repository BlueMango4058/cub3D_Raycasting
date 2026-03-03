/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:16:49 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/03 12:41:47 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;

	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	while (n--)
	{
		*ptr = value;
		ptr++;
	}
	return (s);
}

/*#include <string.h>
#include <stdio.h>

int main(void)
{
	char arr1[] = "0123456789";
	char arr2[] = "0123456789";
	ft_memset(arr1, 'A', 5);
	printf("ft_memset : %s\n", arr1);
	memset(arr2, 'A', 5);
	printf("memset : %s\n", arr2);

	int arr3[3] = {0,};
	int arr4[3] = {0,};
	ft_memset(arr3, 3, 2);
	printf("ft_memset : %d\n", arr3[0]);
	memset(arr4, 3, 2);
	printf("memset : %d\n", arr4[0]);
	return (0);
}*/
