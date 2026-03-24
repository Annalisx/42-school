/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annalisacastaldo <annalisacastaldo@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:27:59 by acastald          #+#    #+#             */
/*   Updated: 2026/03/23 19:40:37 by annalisacas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
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

void	posizione(t_stack_node *stack)
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

void	target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*best;
	t_stack_node	*tmp;
	long			bigg;

	while (b)
	{
		best = NULL;
		bigg = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->nb > b->nb && tmp->nb < bigg)
			{
				bigg = tmp->nb;
				best = tmp;
			}
			tmp = tmp->next;
		}
		if (!best)
			best = min_n(a);
		b->target = best;
		b = b->next;
	}
}

//node->media lo sostituisco con above_median(stack, node).
int	above_median(t_stack_node *stack, t_stack_node *node)
{
	return (node->index <= stack_len(stack) / 2);
}

void	push_cost(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp_b;

	tmp_b = b;
	while (b)
	{
		if (above_median(tmp_b, b) == 1)
			b->push_cost = b->index;
		else
			b->push_cost = stack_len(b) - b->index;
		if (above_median(a, b->target) == 1)// il target di b che sta in a, è sopra la metà di a
			b->push_cost += b->target->index;
		else
			b->push_cost += stack_len(a) - b->target->index;
		b = b->next;
	}
}
