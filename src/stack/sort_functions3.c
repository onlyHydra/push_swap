/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:27:33 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 19:56:50 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->front = stack->front->next;
	stack->rear = stack->rear->next;
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->front = stack->front->prev;
	stack->rear = stack->rear->prev;
}
