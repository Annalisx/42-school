/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:17:24 by acastald          #+#    #+#             */
/*   Updated: 2026/03/12 12:16:06 by acastald         ###   ########.fr       */
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
	if ((s[i] == '+' || s[i] == '-') && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	dupp(t_stack_node *a, long n)
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

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*corr;

	if (!stack || !*stack)
		return ;
	corr = *stack;
	while (corr)
	{
		tmp = corr->next;
		free(corr);
		corr = tmp;
	}
	*stack = NULL;
}

void	nodooo(t_stack_node **stack, long n)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->nb = n;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}
