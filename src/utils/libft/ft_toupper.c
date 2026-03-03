/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:02:50 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/10 10:18:52 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_my_islower(c))
		return (c - ('a' - 'A'));
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char value = 'A';
	int ft_result = ft_toupper(value);
    int origin_result = toupper(value);
	printf("Result: %c\n", ft_result);
    printf("Result: %c\n", origin_result);
    return 0;
}*/
