/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:43:30 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/12 11:24:13 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	get_tokens_size(char **tokens)
{
	size_t	i;

	if (!tokens)
		return (0);
	i = 0;
	while (tokens[i])
		i++;
	return (i);
}
