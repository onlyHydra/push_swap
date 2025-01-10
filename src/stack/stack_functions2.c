/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:12:59 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 04:40:55 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	delete_front(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->front = (stack->front + 1) % stack->capacity;
	stack->size--;
}

void	delete_rear(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->rear = (stack->rear - 1 + stack->capacity) % stack->capacity;
	stack->size--;
}

int	get_front(t_stack *stack)
{
	if (is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->front]);
}

int	get_rear(t_stack *stack)
{
	if (is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->rear]);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}
