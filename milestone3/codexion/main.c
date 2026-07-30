/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:25:14 by acastald          #+#    #+#             */
/*   Updated: 2026/07/30 19:52:57 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	t_info		type;
	t_coders	*coders;
	
	if (ac == 2)
	{
		printf(RED "Invalid number of arguments\n");
		printf("Each argument must be space-separated or enclosed in double quotes.\n" RESET);
		return (1);
	}
	if (ac != 9)
	{
		printf(RED "Invalid number of arguments\n" RESET);
		return (1);
	}
	pars_scheduler(&type, av[8]);
	coders = numbers_of_coders(av[1]);
	if (!coders)
		return (1);
	printf("%d\n", type.algo);
	return (0);
}
