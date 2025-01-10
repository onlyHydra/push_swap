/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hydra <hydra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:47:39 by hydra             #+#    #+#             */
/*   Updated: 2025/01/10 04:04:31 by hydra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(STACK_H)
# define STACK_H

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

#endif // STACK_H
