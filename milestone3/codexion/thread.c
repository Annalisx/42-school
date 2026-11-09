/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:31:24 by acastald          #+#    #+#             */
/*   Updated: 2026/11/09 23:00:49 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*start_routine(void *arg)
{
	t_coders	*num_coder;

	num_coder = (t_coders *)arg;
	while (num_coder->info->running == true)
	{
		print_msg(num_coder, "is compiling");
		print_msg(num_coder, "is debugging");
		print_msg(num_coder, "is refactoring");
	}
	return (NULL);
}

// int	main(void)
// {
// 	pthread_t	thread1;

// 	pthread_create(&thread1, NULL, computation, NULL);
// 	pthread_join(thread1, NULL);
// }

bool	create_threads(t_coders *list, int num_coders)
{
	int			i;
	t_coders	*curr;

	if (!list)
		return (false);
	curr = list;
	i = 0;
	while (i < num_coders)
	{
		if (pthread_create(&curr->thread_id, NULL, &start_routine, curr))
			return (false);
		curr = curr->next;
		i++;
	}
	return (true);
}

bool	join_threads(t_coders *list, int num_coders)
{
	int			i;
	t_coders	*curr;

	if (!list)
		return (false);
	curr = list;
	i = 0;
	while (i < num_coders)
	{
		if (pthread_join(curr->thread_id, NULL))
			return (false);
		curr = curr->next;
		i++;
	}
	return (true);
}

int	init_mutex(t_info *info)
{
	info->running = true;
	if (pthread_mutex_init(&info->mutex_log, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->mutex_running, NULL) != 0)
		return (1);
	return (0);
}
