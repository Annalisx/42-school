/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:56:37 by acastald          #+#    #+#             */
/*   Updated: 2026/03/17 11:36:44 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	*stack = head->next;
	(*stack)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
