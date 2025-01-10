/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:29:06 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 05:49:18 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stack.h"

void	print_stack(t_stack *stack)
{
	while (!is_empty(stack))
	{
		ft_printf("%d ", get_rear(stack));
		delete_rear(stack);
	}
	ft_printf("\n");
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_empty(stack_a))
	{
		if (get_rear(stack_a) == 1)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	while (!is_empty(stack_b))
		push_a(stack_a, stack_b);
}

void	init_stack(t_stack *stack, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		insert_rear(stack, ft_atoi(split[i]));
		free(split[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;

	if (argc == 2)
	{
		stack_a = create_stack(ft_strlen(argv[1]) / 2 + 1);
		stack_b = create_stack(ft_strlen(argv[1]) / 2 + 1);
		split = ft_split(argv[1], ' ');
		init_stack(stack_a, split);
		free(split);
	}
	else
	{
		stack_a = create_stack(argc - 1);
		stack_b = create_stack(argc - 1);
		init_stack(stack_a, argv + 1);
	}
	sort_stack(stack_a, stack_b);
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
