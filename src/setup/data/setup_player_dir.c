/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_player_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:16:58 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/02 13:32:17 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	setup_player_dir(t_player *p)
{
	t_vector	*dir;

	dir = &p->p_dir;
	if (p->start_dir == 'N')
	{
		dir->x = 0;
		dir->y = -1;
	}
	else if (p->start_dir == 'S')
	{
		dir->x = 0;
		dir->y = 1;
	}
	else if (p->start_dir == 'E')
	{
		dir->x = 1;
		dir->y = 0;
	}
	else if (p->start_dir == 'W')
	{
		dir->x = -1;
		dir->y = 0;
	}
}
