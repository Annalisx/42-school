/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:25:27 by acastald          #+#    #+#             */
/*   Updated: 2026/09/23 18:38:53 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_s_info(t_info *info, char **av)
{
	int	i;

	i = 1;
	while (i <= 7)
	{
		if ((check(av[i]) == 1))
			return (1);
		i++;
	}
	info->number_of_coders = ft_atol(av[1]);
	info->time_to_burnout = ft_atol(av[2]);
	info->time_to_compile = ft_atol(av[3]);
	info->time_to_debug = ft_atol(av[4]);
	info->time_to_refactor = ft_atol(av[5]);
	info->number_of_compiles_required = ft_atol(av[6]);
	info->dongle_cooldown = ft_atol(av[7]);
	return (0);
}

int	check(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
	{
		print_error(3);
		return (1);
	}
	while (str[i])
	{
		if (str[0] == '0' && str[1] == '\0')
		{
			print_error(4);
			return (1);
		}
		if (str[i] < '0' || str[i] > '9')
		{
			print_error(6);
			return (1);
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *nptr)
{
	//overflow
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (nptr[i])
	{
		if (n > LONG_MAX / 10 || (n == LONG_MAX / 10 && (nptr[i] - '0') > LONG_MAX % 10))
			return (-1);
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n);
}
