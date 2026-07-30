/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:05:27 by acastald          #+#    #+#             */
/*   Updated: 2026/07/30 20:12:26 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_coders(t_coders *node, t_coders *prev)
{
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	if (!prev)
		node->prev = NULL;
	else
		node->prev = prev;
}
t_coders	*numbers_of_coders(char *str)
{
	int			num_coders;
	int			i;
	t_coders	*head;
	t_coders	*curr;
	t_coders	*prev;

	if (!str || str[0] == '\0')
	{
		printf(RED "Error: empty string\n" RESET);
		return NULL;
	}
	num_coders = atoi(str);
	if (num_coders <= 0)
	{
		printf(RED "Number of coders must be positive\n" RESET);
		return NULL;
	}
	head = malloc(sizeof(t_coders));
	if (!head)
		return NULL;
	head->coder_id = 1;
	init_coders(head, NULL);
	prev = head;
	i = 2;
	while (i <= num_coders)
	{
		curr = malloc(sizeof(t_coders));
		if (curr)
			return NULL;
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
	if (((strcmp(str, "fifo")) != 0) || ((strcmp(str, "edf")) != 0))
	{
		if ((strcmp(str, "fifo")) == 0)
			type->algo = 0;
		else if ((strcmp(str, "edf")) == 0)
			type->algo = 1;
		else
		{
			printf("The value must be exactly one of: fifo or edf.\n");
			return (1);
		}
	}
	return(0);
}
