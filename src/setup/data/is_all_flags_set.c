/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_flags_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:18:17 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/23 12:10:20 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_data.h"

int	is_all_flags_set(int marks)
{
	int	required;

	required = MARK_NO | MARK_SO | MARK_WE | MARK_EA | MARK_F | MARK_C;
	return ((marks & required) == required);
}
