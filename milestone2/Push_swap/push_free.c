/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:56:50 by acastald          #+#    #+#             */
/*   Updated: 2026/04/10 14:44:11 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_listt **a, t_listt **b)
{
	t_listt	*first;
	t_listt	*second;

	if (!b || !*b)
		return ;
	first = *b;
	second = first->next;
	if (second)
		(second)->prev = NULL;
	*b = second;
	first->prev = NULL;
	if (!*a)
	{
		*a = first;
		first->next = NULL;
	}
	else
	{
		first->next = *a;
		(*a)->prev = first;
		*a = first;
	}
	ft_printf("pa\n");
}

void	pb(t_listt **b, t_listt **a)
{
	t_listt	*first;
	t_listt	*second;

	if (!a || !*a)
		return ;
	first = *a;
	second = first->next;
	if (second)
		(second)->prev = NULL;
	*a = second;
	first->prev = NULL;
	if (!*b)
	{
		*b = first;
		first->next = NULL;
	}
	else
	{
		first->next = *b;
		(*b)->prev = first;
		*b = first;
	}
	ft_printf("pb\n");
}

void	free_one_arg(char ***argv)
{
	int		i;

	i = 0;
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
}
