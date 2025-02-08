/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:41:00 by schiper           #+#    #+#             */
/*   Updated: 2025/02/08 13:40:24 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	stack_sorted(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->front;
	while (i < stack->size - 1)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
		i++;
	}
	return (true);
}

t_node	*get_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;
	int		min_index;
	int		i;

	i = 0;
	min_index = INT_MAX;
	node = stack->front;
	min = NULL;
	while (i < stack->size)
	{
		if (node->data < min_index)
		{
			min_index = node->data;
			min = node;
		}
		node = node->next;
		i++;
	}
	return (min);
}

t_node	*get_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;
	int		i;

	i = 0;
	node = stack->front;
	max = node;
	while (i < stack->size)
	{
		if (node->data > max->data)
			max = node;
		node = node->next;
		i++;
	}
	return (max);
}

t_node	*find_cheapest_node(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->front;
	while (i < stack->size)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
		i++;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_node *node, char stack_name)
{
	while (node != (*stack)->front)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				rotate_a(*stack, true);
			else
				reverse_rotate_a(*stack, true);
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				rotate_b(*stack, true);
			else
				reverse_rotate_b(*stack, true);
		}
	}
}
