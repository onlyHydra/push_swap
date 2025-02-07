/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:12:59 by hydra             #+#    #+#             */
/*   Updated: 2025/02/07 17:27:07 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_rear(t_stack *stack, int item)
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
		stack->rear->next = new_node;
		stack->front->prev = new_node;
		stack->rear = new_node;
	}
	stack->size++;
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*front_node;

	if (is_empty(stack))
		return (NULL);
	front_node = stack->front;
	if (stack->size == 1)
	{
		stack->front = NULL;
		stack->rear = NULL;
	}
	else
	{
		stack->front = front_node->next;
		stack->front->prev = stack->rear;
		stack->rear->next = stack->front;
	}
	stack->size--;
	return (front_node);
}

t_node	*pop_rear(t_stack *stack)
{
	t_node	*rear_node;

	if (is_empty(stack))
		return (NULL);
	rear_node = stack->rear;
	if (stack->size == 1)
	{
		stack->front = NULL;
		stack->rear = NULL;
	}
	else
	{
		stack->rear = rear_node->prev;
		stack->rear->next = stack->front;
		stack->front->prev = stack->rear;
	}
	stack->size--;
	return (rear_node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (is_empty(stack))
	{
		free(stack);
		return ;
	}
	current = stack->front;
	while (stack->size > 0)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		stack->size--;
	}
	free(stack);
}

void	stack_print(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->front;
	while (i < stack->size)
	{
		ft_printf("%d ", node->data);
		node = node->next;
		i++;
	}
    ft_printf("\n");
}
