/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:23:09 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 19:42:16 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_a(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	rotate(stack_a);
}

void	rotate_b(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	rotate(stack_b);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	reverse_rotate(stack_a);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	reverse_rotate(stack_b);
}
