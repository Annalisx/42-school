/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:06:24 by acastald          #+#    #+#             */
/*   Updated: 2026/04/10 14:43:51 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_listt *stack)
{
	t_listt	*curr;
	t_listt	*next;

	if (!stack)
		return (1);
	curr = stack;
	next = stack->next;
	while (next != NULL)
	{
		if (curr->nb > next->nb)
			return (0);
		curr = next;
		next = next->next;
	}
	return (1);
}

void	sort_three(t_listt **a)
{
	int	primo;
	int	secondo;
	int	terzo;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	primo = (*a)->nb;
	secondo = (*a)->next->nb;
	terzo = (*a)->next->next->nb;
	if (primo > secondo && primo > terzo)
		ra(a);
	if (secondo > primo && secondo > terzo)
		rra(a);
	primo = (*a)->nb;
	secondo = (*a)->next->nb;
	if (primo > secondo)
		sa(a);
}

void	sort_stack(t_listt **a, t_listt **b)
{
	int	len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(b, a);
	sort_three(a);
	while (*b)
	{
		if (stack_len(*b) == 3)
			sort_three_rev(b);
		posizione(*a);
		posizione(*b);
		target(*a, *b);
		push_cost(*a, *b);
		move_cheap(a, b, cheapest(*b));
	}
	while (min_n(*a) != *a)
	{
		if (above_median(*a, min_n(*a)))
			ra(a);
		else
			rra(a);
	}
}

void	init_stack(t_listt **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (error(argv[i]))
		{
			free_stack(a);
			write(2, "Error\n", 6);
			if (argc == 2)
				free_one_arg(&argv);
			exit(1);
		}
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN || dupp(*a, n))
		{
			free_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		nodooo(a, n);
	}
	if (argc == 2)
		free_one_arg(&argv);
}

int	main(int argc, char **argv)
{
	t_listt	*a;
	t_listt	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&a, argv, argc);
	}
	else
		init_stack(&a, argv + 1, argc);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
