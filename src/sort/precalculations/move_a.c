/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:46:22 by schiper           #+#    #+#             */
/*   Updated: 2025/02/07 19:25:29 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_node *cheapest_node)

{
	while ((*stack_b)->front != cheapest_node->target
		&& (*stack_a)->front != cheapest_node)
		rotate_ab(*stack_a, *stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_node *cheapest_node)

{
	while ((*stack_b)->front != cheapest_node->target
		&& (*stack_a)->front != cheapest_node)
		reverse_rotate_ab(*stack_a, *stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	move_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*target_node;

	target_node = find_cheapest_node(*stack_a);
    printf("Cheapest node %d \n", target_node->data);
	if (target_node->above_median && target_node->target->above_median)
		rotate_both(stack_a, stack_b, target_node);
	else if (target_node->below_median && target_node->target->below_median)
		rev_rotate_both(stack_a, stack_b, target_node);
	prep_for_push(stack_a, target_node, 'a');
	prep_for_push(stack_b, target_node->target, 'b');
	push_b(*stack_a, *stack_b);
}
