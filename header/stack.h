/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:47:39 by hydra             #+#    #+#             */
/*   Updated: 2025/02/07 19:26:52 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(STACK_H)
# define STACK_H

# include "ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

# define PRINT_FLAG true

typedef struct s_node
{
	int				data;
	int				index;
	int				push_cost;
	bool			below_median;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*front;
	t_node			*rear;
	int				size;
	int				capacity;
}					t_stack;

// Stack functions

/** initialize a stack with a given capacity
 *  @param capacity: the capacity of the stack
 */
t_stack				*create_stack(int capacity);
/** check if the stack is empty
 *  @param stack: the stack to check
 *  @return 1 if the stack is empty, 0 otherwise
 */
int					is_empty(t_stack *stack);
/** check if the stack is full
 *  @param stack: the stack to check
 *  @return 1 if the stack is full, 0 otherwise
 */
int					is_full(t_stack *stack);
/** insert an item at the front of the stack
 *  @param stack: the stack to insert the item
 *  @param item: the item to insert
 */
void				push_front(t_stack *stack, int item);
/** insert an item at the rear of the stack
 *  @param stack: the stack to insert the item
 *  @param item: the item to insert
 */
void				push_rear(t_stack *stack, int item);
/** delete an item at the front of the stack
 *  @param stack: the stack to delete the item
 *  @return the deleted item
 */
t_node				*pop_front(t_stack *stack);
/** delete an item at the rear of the stack
 *  @param stack: the stack to delete the item
 *  @return the deleted item
 */
t_node				*pop_rear(t_stack *stack);

/** free the stack
 *  @param stack: the stack to free
 */
void				free_stack(t_stack *stack);

/** rotate the stack
 *  @param stack: the stack to rotate
 */
void				rotate(t_stack *stack);

/** reverse rotate the stack
 *  @param stack: the stack to reverse rotate
 */
void				reverse_rotate(t_stack *stack);

/** print the stack
 *  @param stack: the stack to print
 */
void				stack_print(t_stack *stack);
// Sorting functions

/** swap the first two elements of stack A
 *  @param stack_a: the stack to swap the elements
 */
void				swap_a(t_stack *stack_a, bool print);
/** swap the first two elements of stack B
 *  @param stack_b: the stack to swap the elements
 */
void				swap_b(t_stack *stack_b, bool print);
/** swap the first two elements of both stack A and stack B
 *  @param stack_a: the stack to swap the elements
 *  @param stack_b: the stack to swap the elements
 */
void				swap_ab(t_stack *stack_a, t_stack *stack_b);
/** push the first element of stack A to stack B
 *  @param stack_a: the stack to push the element
 *  @param stack_b: the stack to push the element
 */
void				push_b(t_stack *stack_a, t_stack *stack_b);
/** push the first element of stack B to stack A
 *  @param stack_a: the stack to push the element
 *  @param stack_b: the stack to push the element
 */
void				push_a(t_stack *stack_a, t_stack *stack_b);
/** Shift up all elements of stack a by 1.
The first element becomes the last one.
 *  @param stack_a: the stack to rotate
 */
void				rotate_a(t_stack *stack_a, bool print);
/** Shift up all elements of stack b by 1.
The first element becomes the last one.
 *  @param stack_b: the stack to rotate
 */
void				rotate_b(t_stack *stack_b, bool print);
/** rotate the stack A and stack B at the same time
 *  @param stack_a: the stack to rotate
 *  @param stack_b: the stack to rotate
 */
void				rotate_ab(t_stack *stack_a, t_stack *stack_b);
/** Shift down all elements of stack a by 1.
The last element becomes the first one.
 *  @param stack_a: the stack to reverse rotate
 */
void				reverse_rotate_a(t_stack *stack_a, bool print);
/** Shift down all elements of stack b by 1.
The last element becomes the first one.
 *  @param stack_b: the stack to reverse rotate
 */
void				reverse_rotate_b(t_stack *stack_b, bool print);
/** reverse rotate the stack A and stack B at the same time
 *  @param stack_a: the stack to reverse rotate
 *  @param stack_b: the stack to reverse rotate
 */
void				reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

// Stack utilities

/** check if the stack is sorted
 *  @param stack: the stack to check
 *  @return 1 if the stack is sorted, 0 otherwise
 */
bool				stack_sorted(t_stack *stack);
/** get the minimum element of the stack
 *  @param stack: the stack to get the minimum element
 *  @return the minimum element
 */
t_node				*get_min(t_stack *stack);
/** get the maximum element of the stack
 *  @param stack: the stack to get the maximum element
 *  @return the maximum element
 */
t_node				*get_max(t_stack *stack);

// Sorting algorithms

/** sorts the stack that has only 3 elements in it in ascending order
 * @param list: the stack to sort
 */
void				fast_sort(t_stack *list);

/** sorts the stack that has more than 3 elements in it in ascending order
 * @param stack_a: the stack to sort
 * @param stack_b: the stack to use as a buffer
 */
void				sort_stack(t_stack *stack_a, t_stack *stack_b);

/** moves the cheapest node to the top of the stack
 *  @param stack: the stack to move the cheapest node
 * @param stack_name: the name of the stack
 * @param node: the node to move
 */
void				prep_for_push(t_stack **stack, t_node *node,
						char stack_name);

/** find the cheapest node in the stack
 *  @param stack: the stack to find the cheapest node
 */
t_node				*find_cheapest_node(t_stack *stack);

/** preps a stack to push b nodes
 *  @param stack_a: the stack to prep
 *  @param stack_b: the stack to push to
 */
void				move_b(t_stack **stack_a, t_stack **stack_b);

/** preps cheapest node on top of stack a and pushes to stack b
 *
 */
void				move_a(t_stack **stack_a, t_stack **stack_b);

/**
 *
 */
void				current_index(t_stack *stack);

void				precalculate_a(t_stack *stack_a, t_stack *stack_b);

void				precalculate_b(t_stack *stack_a, t_stack *stack_b);

void				set_cheapest(t_stack *stack);

void				free_errors(t_stack **a);

int					error_syntax(char *str_n);

int					error_duplicate(t_stack *a, int n);

t_stack				*create_empty_stack(int capacity);

#endif // STACK_H
