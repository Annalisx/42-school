/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annalisacastaldo <annalisacastaldo@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:25:14 by acastald          #+#    #+#             */
/*   Updated: 2026/09/22 16:02:45 by annalisacas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	t_info		type;
	t_coders	*coders;

	if (ac == 2)
	{
		print_error(2);
		return (1);
	}
	if (ac != 9)
	{
		print_error(1);
		return (1);
	}
	if (init_s_info(&type, av) == 1)
		return (1);
	coders = numbers_of_coders(type.number_of_coders);
	if (pars_scheduler(&type, av[8]))
		return (1);
	printf("%d\n", type.algo);
	return (0);
}
