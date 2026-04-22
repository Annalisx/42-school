/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:32:42 by acastald          #+#    #+#             */
/*   Updated: 2026/04/10 14:52:24 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_listt
{
	long			nb;
	int				index;
	int				push_cost;
	struct s_listt	*target;
	struct s_listt	*next;
	struct s_listt	*prev;
}	t_listt;

void			swap(t_listt **head);
void			sa(t_listt **a);
void			sb(t_listt **b);
void			pa(t_listt **a, t_listt **b);
void			pb(t_listt **b, t_listt **a);
void			rotate(t_listt **stack);
void			ra(t_listt **a);
void			rb(t_listt **b);
void			rr(t_listt **a, t_listt **b);
void			reverse_rotate(t_listt **stack);
void			rra(t_listt **a);
void			rrb(t_listt **b);
void			rrr(t_listt **a, t_listt **b);
long			ft_atol(const char *nptr);
int				error(char *s);
int				dupp(t_listt *a, long n);
void			free_stack(t_listt **stack);
void			nodooo(t_listt **stack, long n);
void			init_stack(t_listt **a, char **argv, int argc);
int				stack_sorted(t_listt *stack);
int				stack_len(t_listt *stack);
void			sort_three(t_listt **a);
int				above_median(t_listt *stack, t_listt *node);
void			posizione(t_listt *stack);
void			target(t_listt *a, t_listt *b);
t_listt			*min_n(t_listt *stack);
void			push_cost(t_listt *a, t_listt *b);
t_listt			*cheapest(t_listt *stack);
void			move_cheap(t_listt **a, t_listt **b, t_listt *cheap);
void			sort_three_rev(t_listt **b);
t_listt			*trova_best(t_listt *a, t_listt *b);
void			sort_stack(t_listt **a, t_listt **b);
void			free_one_arg(char ***argv);

#endif
