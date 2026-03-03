/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:36:48 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/31 11:47:26 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_data.h"
#include "utils.h"

int	setup_data(t_data *data, const char *filename)
{
	if (parse_data(data, filename) == 0)
		return (0);
	if (final_validate(data) == 0)
		return (0);
	return (1);
}
