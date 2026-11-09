/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:25:14 by acastald          #+#    #+#             */
/*   Updated: 2026/11/09 23:04:00 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	t_info		type;
	t_coders	*coders;

	if (ac != 9)
		return (print_error(1));
	if (init_s_info(&type, av) == 1)
		return (1);
	if (pars_scheduler(&type, av[8]))
		return (1);
	coders = numbers_of_coders(type.number_of_coders, &type);
	if (!coders)
		return (print_error(11));
	type.start_time = get_time_ms();
	if (init_mutex(&type) == 1)
		return (1);
	if (!create_threads(coders, type.number_of_coders))
		return (1);
	join_threads(coders, type.number_of_coders);
	return (0);
}
