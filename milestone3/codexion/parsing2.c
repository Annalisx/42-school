/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:25:27 by acastald          #+#    #+#             */
/*   Updated: 2026/09/21 15:18:49 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	pars(t_info *info, char **av)
{
	int			i;
	
	i = 2;
	numbers_of_coders(av[1]);
	while (i <= 7)
	{
		if (check(av[i] == 1))
			return(1);
		i++;
	}
}

int	check(char *str)
{
	int	i;
	i = 0;

	if (!str || str[0] == '\0')
	{
		print_error(3);
		return(1);
	}
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			print_error(4);
			return (1);
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *nptr)
{
	long	n;
	int	i;

	n = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n);
}
