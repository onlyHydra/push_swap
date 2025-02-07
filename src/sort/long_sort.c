/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:22:51 by schiper           #+#    #+#             */
/*   Updated: 2025/02/07 22:05:27 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	min_on_top(t_stack **stack)
{

	while ((*stack)->front->data != get_min(*stack)->data)
	{
		if (get_min(*stack)->above_median)
			rotate_a(*stack, true);
		else
			reverse_rotate_a(*stack, true);
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 3 && !stack_sorted(stack_a))
		push_b(stack_a, stack_b);
	if (stack_a->size > 3 && !stack_sorted(stack_a))
		push_b(stack_a, stack_b);
	// stack_print(stack_a);
	// stack_print(stack_b);
	// ft_printf("\n");
	while (stack_a->size > 3 && !stack_sorted(stack_a))
	{
		precalculate_a(stack_a, stack_b);
		move_a(&stack_a, &stack_b);
        // stack_print(stack_a);
        // stack_print(stack_b);
        // ft_printf("\n");
        
	}
	// stack_print(stack_a);
	// stack_print(stack_b);
	// stack_print(stack_a);
	fast_sort(stack_a);
	// ft_printf("\n");
    // stack_print(stack_a);
	// stack_print(stack_b);
	while (!is_empty(stack_b))
	{
		precalculate_b(stack_a, stack_b);
		move_b(&stack_a, &stack_b);
	}
	// stack_print(stack_a);
	current_index(stack_a);
	min_on_top(&stack_a);
	// stack_print(stack_a);
}
