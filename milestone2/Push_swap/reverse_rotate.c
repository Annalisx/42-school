/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:55:52 by acastald          #+#    #+#             */
/*   Updated: 2026/03/27 13:46:55 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_listt **stack)
{
	t_listt	*first;
	t_listt	*last;
	t_listt	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	tmp = last->prev;
	tmp->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_listt **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_listt **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_listt **a, t_listt **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
