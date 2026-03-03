/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:13:06 by dsagong           #+#    #+#             */
/*   Updated: 2025/12/23 19:17:12 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_init(t_queue *queue, size_t width, size_t height)
{
	queue->front = 0;
	queue->rear = 0;
	queue->max_size = width * height;
	queue->data = (t_point *)malloc(sizeof(t_point) * queue->max_size);
}

void	enqueue(t_queue *queue, size_t y, size_t x)
{
	queue->data[queue->rear].y = y;
	queue->data[queue->rear].x = x;
	queue->rear++;
}

t_point	dequeue(t_queue *queue)
{
	t_point	p;

	p = queue->data[queue->front];
	queue->front++;
	return (p);
}
