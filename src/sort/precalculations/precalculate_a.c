/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:05:05 by schiper           #+#    #+#             */
/*   Updated: 2025/02/07 22:17:22 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	current_index(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*node;

	i = 0;
	if (!stack)
		return ;
	node = stack->front;
	median = stack->size / 2;
	while (i < stack->size)
	{
		node->index = i + 0;
		if (i <= median)
		{
			node->below_median = false;
			node->above_median = true;
		}
		else if (i > median)
		{
			node->below_median = true;
			node->above_median = false;
		}
		node = node->next;
		i++;
	}
}

static void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_node;
	int		i;

	i = 0;
	a_node = stack_a->front;
	while (i < stack_a->size)
	{
		a_node->push_cost = a_node->index;
		if (!(a_node->above_median))
			a_node->push_cost = stack_a->size - a_node->index;
		if (a_node->target->above_median)
			a_node->push_cost += a_node->target->index;
		else
			a_node->push_cost += stack_b->size - a_node->target->index;
		a_node = a_node->next;
		i++;
	}
}

static t_node	*helper_set_target_a(int *best_match, t_stack *stack_b,
		t_node *node_a)
{
	t_node	*b_node;
	t_node	*target;
	int		i;

	i = 0;
	target = NULL;
	b_node = stack_b->front;
	while (i < stack_b->size)
	{
		if (b_node->data < node_a->data && b_node->data > *best_match)
		{
			*best_match = b_node->data;
			target = b_node;
		}
		b_node = b_node->next;
		i++;
	}
	return (target);
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_node;
	t_node	*target;
	int		best_match;
	int		i;

	i = 0;
	a_node = stack_a->front;
	while (i < stack_a->size)
	{
		best_match = INT_MIN;
		target = helper_set_target_a(&best_match, stack_b, a_node);
		if (best_match == INT_MIN)
			a_node->target = get_max(stack_b);
		else
			a_node->target = target;
		a_node = a_node->next;
		i++;
	}
}

void	precalculate_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
