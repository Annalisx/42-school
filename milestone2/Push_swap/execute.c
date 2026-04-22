/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:02:54 by acastald          #+#    #+#             */
/*   Updated: 2026/04/02 17:30:03 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listt	*cheapest(t_listt *stack)
{
	t_listt	*best;

	if (!stack)
		return (0);
	best = stack;
	while (stack)
	{
		if (best->push_cost > stack->push_cost)
			best = stack;
		stack = stack->next;
	}
	return (best);
}

t_listt	*min_n(t_listt *stack)
{
	t_listt	*min;

	min = stack;
	while (stack)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	move_cheap(t_listt **a, t_listt **b, t_listt *cheap)
{
	while (cheap != *b && cheap->target != *a)
	{
		if (above_median(*b, cheap) && above_median(*a, cheap->target))
			rr(a, b);
		else if (!above_median(*b, cheap) && !above_median(*a, cheap->target))
			rrr(a, b);
		else
			break ;
	}
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

void	sort_three_rev(t_listt **b)
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

int	stack_len(t_listt *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
