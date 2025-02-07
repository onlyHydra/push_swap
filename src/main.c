/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:29:06 by hydra             #+#    #+#             */
/*   Updated: 2025/02/07 17:00:31 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

void	free_errors(t_stack **a)
{
	free_stack(*a);
	ft_printf("Error\n");
	exit(1);
}

static void	populate_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		push_rear(*a, n);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_empty_stack(argc - 1);
	stack_b = create_empty_stack(argc - 1);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	populate_a(&stack_a, argv + 1);
	if (!stack_sorted(stack_a))
	{
		if (stack_a->size == 2)
			swap_a(stack_a, true);
		else if (stack_a->size == 3)
			fast_sort(stack_a);
		else
			sort_stack(stack_a, stack_b);
	}
	//stack_print(stack_a);
	free_stack(stack_a);
	return (0);
}
