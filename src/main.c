/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:29:06 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 23:24:18 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stack.h"

void	print_stack(t_stack *stack)
{
	while (!is_empty(stack))
		ft_printf("%d ", pop_rear(stack)->data);
	ft_printf("\n");
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->capacity == stack_b->capacity)
		return ;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	init_stack(t_stack *stack, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		push_rear(stack, ft_atoi(split[i]));
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
		free_split(split);
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
