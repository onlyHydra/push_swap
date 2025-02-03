/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:22:51 by schiper           #+#    #+#             */
/*   Updated: 2025/02/03 15:22:35 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 3 && !stack_sorted(stack_a))
		push_b(stack_a, stack_b);
	if (stack_a->size > 3 && !stack_sorted(stack_a))
		push_b(stack_a, stack_b);
	while (stack_a->size > 3 && !stack_sorted(stack_a))
	{
		precalculate_a(stack_a, stack_b);
		move_a(&stack_a, &stack_b);
	}
	fast_sort(stack_a);
	while (!is_empty(stack_b))
	{
		precalculate_b(stack_a, stack_b);
		move_b(&stack_a, &stack_b);
	}
}
