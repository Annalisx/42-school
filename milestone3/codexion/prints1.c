/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annalisacastaldo <annalisacastaldo@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:27:22 by acastald          #+#    #+#             */
/*   Updated: 2026/09/23 01:04:12 by annalisacas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_error(int error)
{
	if (error == 1)
		printf(RED "Invalid number of arguments\n" RESET);
	else if (error == 2)
	{
		printf(RED "Invalid number of arguments\nEach argument must be");
		printf(" space-separated or enclosed in double quotes.\n" RESET);
	}
	else if (error == 3)
		printf(RED "Error: empty string\n" RESET);
	else if (error == 4)
	{
		printf(RED "Invalid number\nNumbers must be positive\n");
		printf("The only characters valid are those between 0 and 9.\n" RESET);
	}
	else if (error == 5)
		printf(RED "The value must be exactly one of: fifo or edf.\n" RESET);
	else if (error == 6)
		printf(RED "Invalid number\nNumber cannot be just 0\n" RESET);
	else if (error == 11)
		printf(MY_RED "allocation failed in\n" RESET);
}
