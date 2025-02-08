/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:15:13 by schiper           #+#    #+#             */
/*   Updated: 2025/02/08 13:51:07 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	compare_limits(char *str_n)
{
	const char	*int_max = "2147483647";
	const char	*int_min = "-2147483648";

	if (str_n[0] == '-')
	{
		if (ft_strlen(str_n) > ft_strlen(int_min))
			return (1);
		if (ft_strlen(str_n) == ft_strlen(int_min) && ft_strncmp(str_n, int_min,
				ft_strlen(int_min) + 1) > 0)
			return (1);
	}
	else
	{
		if (ft_strlen(str_n) > ft_strlen(int_max))
			return (1);
		if (ft_strlen(str_n) == ft_strlen(int_max) && ft_strncmp(str_n, int_max,
				ft_strlen(int_max) + 1) > 0)
			return (1);
	}
	return (0);
}

int	error_syntax(char *str_n)
{
	if (ft_strlen(str_n) == 0 || ft_strlen(str_n) > 11)
		return (1);
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	if (compare_limits(str_n))
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
	int		i;

	i = 0;
	tmp = a->front;
	if (tmp == NULL)
		return (0);
	if (tmp == a->rear && tmp->data == n)
		return (1);
	while (i < a->size)
	{
		if (tmp->data == n)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
