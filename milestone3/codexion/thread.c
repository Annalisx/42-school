/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:31:24 by acastald          #+#    #+#             */
/*   Updated: 2026/11/07 15:18:28 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*start_routine(void *arg)
{
	t_coders	*num_coder;

	num_coder = (t_coders *)arg;
	while (!end_program || !burnout)
	{
		print_msg(num_coder, "is compiling");
		print_msg(num_coder, "is debugging");
		print_msg(num_coder, "is refactoring");
		return (0);
	}
	return (NULL);
}

// int	main(void)
// {
// 	pthread_t	thread1;

// 	pthread_create(&thread1, NULL, computation, NULL);
// 	pthread_join(thread1, NULL);
// }

bool	create_threads(t_coders *list, t_info info, int num_coders)
{
	int			i;
	t_coders	*curr;

	curr = list;
	i = 0;
	if (num_coders == 1)
	{
		if (pthread_create(&curr->thread_id, NULL, &start_routine, num_coders))
			return (false);
		return (true);
	}
	else if (num_coders >= 1)
	{
		if (pthread_create(&list->thread_id, NULL, &start_routine, NULL))
			return (false);
		num_coders = info.number_of_coders;
		return (true);
	}
	return (false);
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
