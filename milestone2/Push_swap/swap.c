/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:44:07 by acastald          #+#    #+#             */
/*   Updated: 2026/03/27 13:46:55 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_listt **stack)
{
	t_listt	*first;
	t_listt	*second;
	t_listt	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	tmp = first;
	first = first->next;
	if (first)
		first->prev = NULL;
	second = tmp;
	tmp = first->next;
	first->next = second;
	second->prev = first;
	second->next = tmp;
	if (tmp)
		tmp->prev = second;
	*stack = first;
}

void	sa(t_listt **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_listt **b)
{
	swap(b);
	ft_printf("sb\n");
}
