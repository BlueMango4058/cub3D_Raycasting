/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:08:09 by dsagong           #+#    #+#             */
/*   Updated: 2026/01/19 16:41:22 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "init.h"
#include "setup.h"
#include "minilibx-linux/mlx.h"
#include "render.h"
#include "hook.h"

/*
****************[process]*******************
1. Validation - av_validate
2. Resources Setup - setup_resources
3. Initial Rendering - render_image
4. Interaction Loop - hook_events, mlx_loop
********************************************
*/
int	main(int ac, char **av)
{
	t_ctx	ctx;

	av_validate(ac, av);
	init_resources(&ctx);
	if (!setup_resources(&ctx, av[1]))
		free_resources(&ctx, 1);
	print_data(&ctx.data, 1);
	render_image(&ctx);
	hook_events(&ctx);
	mlx_loop(ctx.mlx.mlx_ptr);
	return (0);
}
