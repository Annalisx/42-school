/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:27:59 by acastald          #+#    #+#             */
/*   Updated: 2026/03/25 17:42:03 by acastald         ###   ########.fr       */
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
	return (node->index <= (stack_len(stack) / 2));
}

void	push_cost(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp_b;
	int cost_a;

	tmp_b = b;
	cost_a = 0;
	while (b)
	{
		if (above_median(tmp_b, b) == 1)
			b->push_cost = b->index;
		else
			b->push_cost = stack_len(tmp_b) - b->index;
		if (above_median(a, b->target) == 1)// il target di b che sta in a, è sopra la metà di a
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

/* void push_cost(t_stack_node *a, t_stack_node *b)
{
    int len_a = stack_len(a);
    int len_b = stack_len(b);
    int cost_a, cost_b;

    while (b)
    {
        // Calculate raw distances
        cost_b = above_median(b, b) ? b->index : len_b - b->index;
        cost_a = above_median(a, b->target) ? b->target->index : len_a - b->target->index;

        // If they travel in the same direction, cost is the max of the two
        if (above_median(b, b) == above_median(a, b->target))
        {
            if (cost_a > cost_b)
                b->push_cost = cost_a;
            else
                b->push_cost = cost_b;
        }
        // If they travel in opposite directions, cost is the sum
        else
        {
            b->push_cost = cost_a + cost_b;
        }
        b = b->next;
    }
} */
