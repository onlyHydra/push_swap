/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:05:24 by schiper           #+#    #+#             */
/*   Updated: 2025/02/07 20:35:25 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	set_cheapest(t_stack *stack)
{
	t_node	*node;
	t_node	*cheapest;
	int		cheapest_value;
	int		i;

	i = 0;
	node = stack->front;
	cheapest_value = INT_MAX;
	while (i < stack->size)
	{
		if (node->push_cost < cheapest_value)
		{
			cheapest = node;
			cheapest_value = node->push_cost;
		}
		node = node->next;
		i++;
	}
	cheapest->cheapest = true;
}

static t_node	*helper_set_target_b(int *best_match, t_stack *stack_a,
		t_node *node_b)
{
	t_node	*a_node;
	t_node	*target;
	int		i;

	i = 0;
	a_node = stack_a->front;
	while (i < stack_a->size)
	{
		if (a_node->data > node_b->data && a_node->data < *best_match)
		{
			*best_match = a_node->data;
			target = a_node;
		}
		a_node = a_node->next;
		i++;
	}
	return (target);
}

static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_b;
	t_node	*target;
	int		best_match;
	int		i;

	i = 0;
	node_b = stack_b->front;
	while (i < stack_b->size)
	{
		best_match = INT_MAX;
		target = helper_set_target_b(&best_match, stack_a, node_b);
		if (best_match == INT_MAX)
			node_b->target = get_min(stack_a);
		else
			node_b->target = target;
		node_b = node_b->next;
		i++;
	}
}

void	precalculate_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
