/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:36:06 by schiper           #+#    #+#             */
/*   Updated: 2025/02/07 17:00:10 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	move_b(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->front->target, 'a');
	//stack_print(*stack_a);
	//ft_printf("\n");
	push_a(*stack_a, *stack_b);
	//stack_print(*stack_a);
	//ft_printf("\n");
}
