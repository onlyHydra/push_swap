/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:27:34 by schiper           #+#    #+#             */
/*   Updated: 2025/02/03 17:32:13 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = NULL;
	stack->front = NULL;
	stack->rear = NULL;
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (stack->size == 0);
}

int	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

void	push_front(t_stack *stack, int item)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = item;
	if (is_empty(stack))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->front = new_node;
		stack->rear = new_node;
	}
	else
	{
		new_node->next = stack->front;
		new_node->prev = stack->rear;
		stack->front->prev = new_node;
		stack->rear->next = new_node;
		stack->front = new_node;
	}
	stack->size++;
}

t_stack	*create_empty_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = NULL;
	stack->front = NULL;
	stack->rear = NULL;
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}
