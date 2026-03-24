/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:55:49 by acastald          #+#    #+#             */
/*   Updated: 2026/03/05 15:22:53 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_print_nbr(int nb)
{
	int		len;
	char	c;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += ft_print_nbr(nb / 10);
	}
	c = nb % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_print_unbr(unsigned int nb)
{
	int		len;
	char	c;

	len = 0;
	if (nb >= 10)
	{
		len += ft_print_unbr(nb / 10);
	}
	c = nb % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}
