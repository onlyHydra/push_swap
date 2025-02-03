/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:23:09 by hydra             #+#    #+#             */
/*   Updated: 2025/02/03 15:44:37 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_a(t_stack *stack_a, bool print)
{
	if (stack_a->size < 2)
		return ;
	rotate(stack_a);
	if (PRINT_FLAG && print)
		ft_printf("ra\n");
}

void	rotate_b(t_stack *stack_b, bool print)
{
	if (stack_b->size < 2)
		return ;
	rotate(stack_b);
	if (PRINT_FLAG && print)
		ft_printf("rb\n");
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, false);
	rotate_b(stack_b, false);
	if (PRINT_FLAG)
		ft_printf("rr\n");
}

void	reverse_rotate_a(t_stack *stack_a, bool print)
{
	if (stack_a->size < 2)
		return ;
	reverse_rotate(stack_a);
	if (print && PRINT_FLAG)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *stack_b, bool print)
{
	if (stack_b->size < 2)
		return ;
	reverse_rotate(stack_b);
	if (PRINT_FLAG && print)
		ft_printf("rrb\n");
}
