/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:47:39 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 04:40:32 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(STACK_H)
# define STACK_H

# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*array;
	int	front;
	int	rear;
	int	size;
	int	capacity;
}		t_stack;

/** initialize a stack with a given capacity
 *  @param capacity: the capacity of the stack
 */
t_stack	*create_stack(int capacity);
/** check if the stack is empty
 *  @param stack: the stack to check
 *  @return 1 if the stack is empty, 0 otherwise
 */
int		is_empty(t_stack *stack);
/** check if the stack is full
 *  @param stack: the stack to check
 *  @return 1 if the stack is full, 0 otherwise
 */
int		is_full(t_stack *stack);
/** insert an item at the front of the stack
 *  @param stack: the stack to insert the item
 *  @param item: the item to insert
 */
void	insert_front(t_stack *stack, int item);
/** insert an item at the rear of the stack
 *  @param stack: the stack to insert the item
 *  @param item: the item to insert
 */
void	insert_rear(t_stack *stack, int item);
/** delete an item at the front of the stack
 *  @param stack: the stack to delete the item
 */
void	delete_front(t_stack *stack);
/** delete an item at the rear of the stack
 *  @param stack: the stack to delete the item
 */
void	delete_rear(t_stack *stack);
/** get the front item of the stack
 *  @param stack: the stack to get the item
 *  @return the front item of the stack
 */
int		get_front(t_stack *stack);
/** get the rear item of the stack
 *  @param stack: the stack to get the item
 *  @return the rear item of the stack
 */
int		get_rear(t_stack *stack);

/** free the stack
 *  @param stack: the stack to free
 */
void	free_stack(t_stack *stack);

// Sorting functions

/** swap the first two elements of stack A
 *  @param stack_a: the stack to swap the elements
 */
void	swap_a(t_stack *stack_a);
/** swap the first two elements of stack B
 *  @param stack_b: the stack to swap the elements
 */
void	swap_b(t_stack *stack_b);
/** swap the first two elements of both stack A and stack B
 *  @param stack_a: the stack to swap the elements
 *  @param stack_b: the stack to swap the elements
 */
void	swap_ab(t_stack *stack_a, t_stack *stack_b);
/** push the first element of stack A to stack B
 *  @param stack_a: the stack to push the element
 *  @param stack_b: the stack to push the element
 */
void	push_b(t_stack *stack_a, t_stack *stack_b);
/** push the first element of stack B to stack A
 *  @param stack_a: the stack to push the element
 *  @param stack_b: the stack to push the element
 */
void	push_a(t_stack *stack_a, t_stack *stack_b);
/** Shift up all elements of stack a by 1.
The first element becomes the last one.
 *  @param stack_a: the stack to rotate
 */
void	rotate_a(t_stack *stack_a);
/** Shift up all elements of stack b by 1.
The first element becomes the last one.
 *  @param stack_b: the stack to rotate
 */
void	rotate_b(t_stack *stack_b);
/** rotate the stack A and stack B at the same time
 *  @param stack_a: the stack to rotate
 *  @param stack_b: the stack to rotate
 */
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);
/** Shift down all elements of stack a by 1.
The last element becomes the first one.
 *  @param stack_a: the stack to reverse rotate
 */
void	reverse_rotate_a(t_stack *stack_a);
/** Shift down all elements of stack b by 1.
The last element becomes the first one.
 *  @param stack_b: the stack to reverse rotate
 */
void	reverse_rotate_b(t_stack *stack_b);
/** reverse rotate the stack A and stack B at the same time
 *  @param stack_a: the stack to reverse rotate
 *  @param stack_b: the stack to reverse rotate
 */
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

#endif // STACK_H
