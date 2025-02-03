/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:36:06 by schiper           #+#    #+#             */
/*   Updated: 2025/02/03 15:23:07 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	move_b(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->front->target, 'a');
	push_a(*stack_a, *stack_b);
}
