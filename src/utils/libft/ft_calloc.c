/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:42:19 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/07 10:13:08 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	ft_memset(result, 0, size * nmemb);
	return (result);
}
