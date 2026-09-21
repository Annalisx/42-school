/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:25:14 by acastald          #+#    #+#             */
/*   Updated: 2026/09/21 15:02:02 by acastald         ###   ########.fr       */
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
	coders = numbers_of_coders(av[1]);
	if (!coders)
		return (1);
	if (pars(&type, av) == 1)
		return (1);
	if (pars_scheduler(&type, av[8]))
		return (1);
	printf("%d\n", type.algo);
	return (0);
}


