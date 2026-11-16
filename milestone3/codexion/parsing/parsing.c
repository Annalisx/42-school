/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:05:27 by acastald          #+#    #+#             */
/*   Updated: 2026/11/16 20:49:18 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	init_dongle(t_info *info)
{
	int	i;

	i = 0;
	info->dongles = malloc(sizeof(t_dongles) * info->number_of_coders);
	if (!info->dongles)
		return (print_merror(11));
	while (i < info->number_of_coders)
	{
		info->dongles[i].dongle_id = i;
		info->dongles[i].active = true;
		if (pthread_mutex_init(&info->dongles[i].lock, NULL) != 0)
			return (print_merror(12));
		i++;
	}
	return (0);
}

void	init_coders(t_coders *node, t_coders *prev, t_info *type)
{
	node->info = type;
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

t_coders	*numbers_of_coders(long num_coders, t_info *type)
{
	int			i;
	t_coders	*head;
	t_coders	*curr;
	t_coders	*prev;

	head = malloc(sizeof(t_coders));
	if (!head)
		return (NULL);
	init_coders(head, NULL, type);
	prev = head;
	i = 2;
	while (i <= num_coders)
	{
		curr = malloc(sizeof(t_coders));
		if (!curr)
			return (NULL);
		curr->coder_id = i;
		init_coders(curr, prev, type);
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
	if (!str || str[0] == '\0')
	{
		print_error(3);
		return (1);
	}
	if (((strcmp(str, "fifo")) != 0) && ((strcmp(str, "edf")) != 0))
	{
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
	//free_all(type->number_of_coders);
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

// 	list = numbers_of_coders(0);
// 	if (list)
// 		print_all_coders(list);
// 	return (0);
// }
