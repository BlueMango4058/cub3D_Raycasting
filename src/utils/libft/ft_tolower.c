/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:35:11 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/10 10:18:48 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_my_isupper(c))
		return (c + ('a' - 'A'));
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	value = 'A';
	printf("ft : %c\n", ft_tolower(value));
	printf("original : %c\n", tolower(value));
	return (0);
}*/