/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:05:24 by schiper           #+#    #+#             */
/*   Updated: 2025/02/03 15:12:58 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*target;
	int		best_match;

	node_b = stack_b->front;
	while (node_b)
	{
		best_match = INT_MAX;
		node_a = stack_a->front;
		while (node_a)
		{
			if (node_a->data < node_b->data && node_a->data < best_match)
			{
				best_match = node_a->data;
				target = node_a;
			}
			node_a = node_a->next;
		}
		if (best_match == INT_MAX)
			node_b->target = get_min(stack_a);
		else
			node_b->target = target;
		node_b = node_b->next;
	}
}

void	precalculate_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
