/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:02:54 by acastald          #+#    #+#             */
/*   Updated: 2026/03/24 15:00:24 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*cheapest(t_stack_node *stack)
{
	t_stack_node	*best;
	long			bigg;

	if (!stack)
		return (0);
	bigg = LONG_MAX;
	best = NULL;
	while (stack)
	{
		if (stack->push_cost < bigg)
		{
			bigg = stack->push_cost;
			best = stack;
		}
		stack = stack->next;
	}
	return (best);
}

t_stack_node	*min_n(t_stack_node *stack)
{
	t_stack_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	move_cheap(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (cheap != *b)
	{
		if (above_median(*b, cheap))
			rb(b);
		else
			rrb(b);
	}
	while (cheap->target != *a)
	{
		if (above_median(*a, cheap->target))
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}

void	sort_three_rev(t_stack_node **b)
{
	int	primo;
	int	secondo;
	int	terzo;

	if (!b || !*b || !(*b)->next || !(*b)->next->next)
		return ;
	primo = (*b)->nb;
	secondo = (*b)->next->nb;
	terzo = (*b)->next->next->nb;
	if (primo < secondo && primo < terzo)
		rb(b);
	if (secondo < primo && secondo < terzo)
		rrb(b);
	primo = (*b)->nb;
	secondo = (*b)->next->nb;
	if (primo < secondo)
		sb(b);
}
