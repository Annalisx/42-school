/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annalisacastaldo <annalisacastaldo@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:31:24 by acastald          #+#    #+#             */
/*   Updated: 2026/11/11 00:50:43 by annalisacas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*start_routine(void *arg)
{
	t_coders	*num_coder;

	num_coder = (t_coders *)arg;
	while (num_coder->info->running == true)
	{
		compiling(num_coder);
		debugging(num_coder);
		refactoring(num_coder);
	}
	return (NULL);
}

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
		return (print_merror(12));
	if (pthread_mutex_init(&info->mutex_running, NULL) != 0)
		return (print_merror(12));
	if (init_dongle(info) != 0)
		return (1);
	return (0);
}
