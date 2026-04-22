/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:56:37 by acastald          #+#    #+#             */
/*   Updated: 2026/03/27 13:46:55 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_listt **stack)
{
	t_listt	*first;
	t_listt	*second;
	t_listt	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	second->prev = NULL;
	last = second;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*stack = second;
}

void	ra(t_listt **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_listt **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_listt **a, t_listt **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
