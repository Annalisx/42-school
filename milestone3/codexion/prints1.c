/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:27:22 by acastald          #+#    #+#             */
/*   Updated: 2026/09/21 15:15:36 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_error(int error)
{
	if (error == 1)
		printf(RED "Invalid number of arguments\n");
	else if (error == 2)
	{
		printf(RED "Invalid number of arguments\n");
		printf("Each argument must be space-separated or enclosed in double quotes.\n" RESET);
	}
	else if (error == 3)
		printf(RED "Error: empty string\n" RESET);
	else if (error == 4)
		{
			printf(RED "Invalid number\n");
			printf(RED "Number of coders must be positive\n" RESET);
			printf("The only characters accepted are those between 0 and 9.\n" RESET);
		}
	else if (error == 5)
	printf(RED "The value must be exactly one of: fifo or edf.\n" RESET);
	else if (error == 6)
	else if (error == 7)
		printf(RED "1111111111\n" RESET);
}
