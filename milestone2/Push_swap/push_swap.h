/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:32:42 by acastald          #+#    #+#             */
/*   Updated: 2026/03/25 15:07:30 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	long				nb;
	int					index;
	int					push_cost;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//funzioni non statiche 

void			swap(t_stack_node **head);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
long			ft_atol(const char *nptr);
int				error(char *s);
int				dupp(t_stack_node *a, long n);
void			free_stack(t_stack_node **stack);
void			nodooo(t_stack_node **stack, long n);
void			init_stack(t_stack_node **a, char **argv);
int				stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			sort_three(t_stack_node **a);
int				above_median(t_stack_node *stack, t_stack_node *node);
void			posizione(t_stack_node *stack);
void			target(t_stack_node *a, t_stack_node *b);
t_stack_node	*min_n(t_stack_node *stack);
void			push_cost(t_stack_node *a, t_stack_node *b);
t_stack_node	*cheapest(t_stack_node *stack);
void			move_cheap(t_stack_node **a, t_stack_node **b, t_stack_node *cheap);
void			sort_three_rev(t_stack_node **b);

#endif
