/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:23:09 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 04:27:59 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_a(t_stack *stack_a)
{
	int	value;

	if (stack_a->size < 2)
		return ;
	value = get_front(stack_a);
	delete_front(stack_a);
	insert_rear(stack_a, value);
}

void	rotate_b(t_stack *stack_b)
{
	int	value;

	if (stack_b->size < 2)
		return ;
	value = get_front(stack_b);
	delete_front(stack_b);
	insert_rear(stack_b, value);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	int	value;

	if (stack_a->size < 2)
		return ;
	value = get_rear(stack_a);
	delete_rear(stack_a);
	insert_front(stack_a, value);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	int	value;

	if (stack_b->size < 2)
		return ;
	value = get_rear(stack_b);
	delete_rear(stack_b);
	insert_front(stack_b, value);
}
