/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:02:36 by schiper           #+#    #+#             */
/*   Updated: 2025/01/11 00:07:43 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fast_sort(t_stack *list)
{
	t_node	*biggest_node;

	biggest_node = get_max(list);
	if (biggest_node == list->front)
		rotate_a(list);
	else if (biggest_node == list->front->next)
		reverse_rotate_a(list);
	if (list->front->data > list->front->next->data)
		swap_a(list);
}