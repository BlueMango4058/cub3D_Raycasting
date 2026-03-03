/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:25:19 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/02 13:37:39 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"

void	*ft_memset(void *s, int c, size_t n);

void	init_resources(t_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(*ctx));
}
