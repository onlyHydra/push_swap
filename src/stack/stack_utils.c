/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:41:00 by schiper           #+#    #+#             */
/*   Updated: 2025/01/10 23:50:02 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	stack_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->front;
	while (node->next != stack->front)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}

t_node	*get_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	node = stack->front;
	min = node;
	while (node->next != stack->front)
	{
		if (node->data < min->data)
			min = node;
		node = node->next;
	}
	return (min);
}

t_node	*get_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	node = stack->front;
	max = node;
	while (node->next != stack->front)
	{
		if (node->data > max->data)
			max = node;
		node = node->next;
	}
	return (max);
}
