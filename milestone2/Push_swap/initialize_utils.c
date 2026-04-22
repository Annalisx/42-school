/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:17:24 by acastald          #+#    #+#             */
/*   Updated: 2026/03/27 13:46:55 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	n;
	int		neg;
	int		i;

	n = 0;
	neg = 1;
	i = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n * neg);
}

int	error(char *s)
{
	int	i;

	i = 0;
	if (!((s[i] == '+' || s[i] == '-') || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	dupp(t_listt *a, long n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_listt **stack)
{
	t_listt	*tmp;
	t_listt	*node;

	if (!stack || !*stack)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

void	nodooo(t_listt **stack, long n)
{
	t_listt	*new;
	t_listt	*last;

	if (!stack)
		return ;
	new = malloc(sizeof(t_listt));
	if (!new)
		return ;
	new->nb = n;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}
