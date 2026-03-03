/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:19:49 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/23 19:44:06 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

typedef struct s_queue
{
	t_point	*data;
	size_t	front;
	size_t	rear;
	size_t	max_size;
}	t_queue;

void	queue_init(t_queue *queue, size_t width, size_t height);
void	enqueue(t_queue *queue, size_t y, size_t x);
t_point	dequeue(t_queue *queue);

#endif
