/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:25:14 by acastald          #+#    #+#             */
/*   Updated: 2026/07/23 18:46:31 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	main(int ac, char **av)
{
	t_coders type;
	
	if (ac == 2)
	{
		printf("\x1b[31mInvalid number of arguments\x1b[31m\n");
		printf("\033[0mEach argument must be space-separated or enclosed in double quotes.\033[0m\n");
		return (1);
	}
	if (ac != 9)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	if (((strcmp(av[8], "fifo")) != 0) || ((strcmp(av[8], "edf")) != 0))
	{
		if ((strcmp(av[8], "fifo")) == 0)
			type.algo = 0;
		else if ((strcmp(av[8], "edf")) == 0)
			type.algo = 1;
		else
		{
			printf("The value must be exactly one of: fifo or edf.\n");
			return (1);
		}
		printf("%d\n", type.algo);
	}
	return (0);
}
