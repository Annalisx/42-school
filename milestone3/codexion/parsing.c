/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:05:27 by acastald          #+#    #+#             */
/*   Updated: 2026/09/21 20:10:46 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_coders(t_coders *node, t_coders *prev)
{
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	if (!prev)
	{
		node->coder_id = 1;
		node->prev = NULL;
	}
	else
		node->prev = prev;
}

t_coders	*numbers_of_coders(long num_coders)
{
	int			i;
	t_coders	*head;
	t_coders	*curr;
	t_coders	*prev;

	head = malloc(sizeof(t_coders));
	if (!head)
		return (NULL);
	init_coders(head, NULL);
	prev = head;
	i = 2;
	while (i <= num_coders)
	{
		curr = malloc(sizeof(t_coders));
		if (!curr)
			return (NULL);
		curr->coder_id = i;
		init_coders(curr, prev);
		prev->next = curr;
		prev = curr;
		i++;
	}
	prev->next = head;
	head->prev = prev;
	return (head);
}

int	pars_scheduler(t_info *type, char *str)
{
	if (((strcmp(str, "fifo")) != 0) && ((strcmp(str, "edf")) != 0))
	{
		if (!str || str[0] == '\0')
			print_error(3);
		print_error(5);
		return (1);
	}
	if ((strcmp(str, "fifo")) == 0)
	{
		type->algo = 0;
		return (0);
	}
	else if ((strcmp(str, "edf")) == 0)
	{
		type->algo = 1;
		return (0);
	}
	return (1);
}
// void print_all_coders(t_coders *head)
// {
// 	t_coders *curr;

// 	if (!head)
// 		return;
// 	curr = head;
// 	do
// 	{
// 		printf("id: %d\n", curr->coder_id);
// 		curr = curr->next;
// 	} while (curr != head);
// }

// int main(void)
// {
// 	t_coders *list;

// 	list = numbers_of_coders("");
// 	if (list)
// 		print_all_coders(list);
// 	return (0);
// }
