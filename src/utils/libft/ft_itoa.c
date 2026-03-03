/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:59:15 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/08 12:57:19 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_len(int n)
{
	size_t	len;
	long	num;

	num = n;
	len = 0;
	if (num <= 0)
	{
		len++;
		num = -num;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	put_value(long num, size_t len, char *result)
{
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (num)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	long	num;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = itoa_len(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	put_value(num, len, result);
	return (result);
}
