/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:11:45 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 04:12:43 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	stack->size = 0;
	stack->front = 0;
	stack->rear = capacity - 1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

void	insert_front(t_stack *stack, int item)
{
	if (is_full(stack))
		return ;
	stack->front = (stack->front - 1 + stack->capacity) % stack->capacity;
	stack->array[stack->front] = item;
	stack->size++;
}

void	insert_rear(t_stack *stack, int item)
{
	if (is_full(stack))
		return ;
	stack->rear = (stack->rear + 1) % stack->capacity;
	stack->array[stack->rear] = item;
	stack->size++;
}
