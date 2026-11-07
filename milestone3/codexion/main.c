/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:25:14 by acastald          #+#    #+#             */
/*   Updated: 2026/11/07 15:04:15 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	t_info		type;
	t_coders	*coders;

	if (ac != 9)
	{
		print_error(1);
		return (1);
	}
	if (init_s_info(&type, av) == 1)
		return (1);
	if (pars_scheduler(&type, av[8]))
		return (1);
	coders = numbers_of_coders(type.number_of_coders, &type);
	if (!coders)
	{
		print_error(11);
		return (1);
	}
	printf("%d\n", type.algo);
	type.start_time = get_time_ms();
	if (init_mutex(&type) == 1)
		return (1);
	//crea threads
	//pthread join
	return (0);
}
