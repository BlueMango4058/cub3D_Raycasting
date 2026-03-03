/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:34:13 by dsagong           #+#    #+#             */
/*   Updated: 2025/04/09 12:36:03 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	if (!lst)
		return (len);
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

/*#include <stdio.h>
int	main(void)
{
	t_list *a = ft_lstnew("one");
	t_list *b = ft_lstnew("two");
	t_list *c = ft_lstnew("three");
	a->next = b;
	b->next = c;

	printf("%d\n", ft_lstsize(a));  // 출력: 3
}*/