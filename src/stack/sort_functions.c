/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:16:50 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 19:41:31 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_a(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (stack_a->size < 2)
		return ;
	first = stack_a->front;
	second = first->next;
	tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

void	swap_b(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (stack_b->size < 2)
		return ;
	first = stack_b->front;
	second = first->next;
	tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (is_empty(stack_a))
		return ;
	node = pop_front(stack_a);
	if (node)
	{
		push_front(stack_b, node->data);
		free(node);
	}
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (is_empty(stack_b))
		return ;
	node = pop_front(stack_b);
	if (node)
	{
		push_front(stack_a, node->data);
		free(node);
	}
}
