/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:27:59 by acastald          #+#    #+#             */
/*   Updated: 2026/04/02 17:29:32 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	posizione(t_listt *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	target(t_listt *a, t_listt *b)
{
	while (b)
	{
		b->target = trova_best(a, b);
		b = b->next;
	}
}

t_listt	*trova_best(t_listt *a, t_listt *b)
{
	t_listt	*best;
	t_listt	*tmp;

	best = NULL;
	tmp = a;
	while (tmp)
	{
		if (tmp->nb > b->nb)
		{
			best = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (best->nb > tmp->nb && tmp->nb > b->nb)
			best = tmp;
		tmp = tmp->next;
	}
	if (!best)
		best = min_n(a);
	return (best);
}

int	above_median(t_listt *stack, t_listt *node)
{
	if (node->index <= (stack_len(stack) / 2))
		return (1);
	return (0);
}

void	push_cost(t_listt *a, t_listt *b)
{
	t_listt	*tmp_b;
	int		cost_a;

	tmp_b = b;
	cost_a = 0;
	while (b)
	{
		if (above_median(tmp_b, b) == 1)
			b->push_cost = b->index;
		else
			b->push_cost = stack_len(tmp_b) - b->index;
		if (above_median(a, b->target) == 1)
			cost_a = b->target->index;
		else
			cost_a = stack_len(a) - b->target->index;
		if (above_median(tmp_b, b) == above_median(a, b->target))
		{
			if (b->push_cost < cost_a)
				b->push_cost = cost_a;
		}
		else
			b->push_cost += cost_a;
		b = b->next;
	}
}
