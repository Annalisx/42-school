/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:31:24 by acastald          #+#    #+#             */
/*   Updated: 2026/10/12 18:21:59 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*start_routine(int num_coders)
{
	while (num_coders)
	{
		// compiling
		// debugging
		// refactoring
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
