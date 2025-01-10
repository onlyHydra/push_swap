/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:16:50 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 04:23:04 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_a(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size < 2)
		return ;
	tmp = stack_a->array[stack_a->front];
	stack_a->array[stack_a->front] = stack_a->array[(stack_a->front + 1)
		% stack_a->capacity];
	stack_a->array[(stack_a->front + 1) % stack_a->capacity] = tmp;
}

void	swap_b(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size < 2)
		return ;
	tmp = stack_b->array[stack_b->front];
	stack_b->array[stack_b->front] = stack_b->array[(stack_b->front + 1)
		% stack_b->capacity];
	stack_b->array[(stack_b->front + 1) % stack_b->capacity] = tmp;
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (is_empty(stack_a))
		return ;
	value = get_front(stack_a);
	delete_front(stack_a);
	insert_front(stack_b, value);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (is_empty(stack_b))
		return ;
	value = get_front(stack_b);
	delete_front(stack_b);
	insert_front(stack_a, value);
}
