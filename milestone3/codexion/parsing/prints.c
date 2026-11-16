/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:27:22 by acastald          #+#    #+#             */
/*   Updated: 2026/11/16 19:03:39 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	print_error(int error)
{
	if (error == 1)
	{
		printf(RED "Invalid number of arguments\nEach argument must be");
		printf(" space-separated or enclosed in double quotes.\n" RESET);
		return (1);
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
	return (0);
}

int	print_merror(int error)
{
	if (error == 11)
	{
		printf(MY_RED "allocation failed in\n" RESET);
		return (1);
	}
	else if (error == 12)
	{
		printf(MY_RED "mutex initialization failed in\n" RESET);
		return (1);
	}
	return (0);
}

void	print_msg(t_coders *coder, char *str)
{
	pthread_mutex_lock(&coder->info->mutex_log);
	printf("%ld %d %s\n", timestamp(coder->info), coder->coder_id, str);
	pthread_mutex_unlock(&coder->info->mutex_log);
}

void	print_dongles(t_coders *pos, char *str)
{
	t_dongles	*dongle;

	dongle = NULL;
	if (dongle == pos->left)
	{
		printf("%ld %d %s\n", timestamp(pos->info), pos->coder_id, str);
	}
	if (dongle == pos->right)
	{
		printf("%ld %d %s\n", timestamp(pos->info), pos->coder_id, str);
	}
}
