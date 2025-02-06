/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:15:13 by schiper           #+#    #+#             */
/*   Updated: 2025/02/03 17:36:45 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	t_node	*tmp;

	tmp = a->front;
	if (tmp == NULL)
		return (0);
	if (tmp == a->rear && tmp->data == n)
		return (1);
	while (tmp != a->rear)
	{
		if (tmp->data == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
