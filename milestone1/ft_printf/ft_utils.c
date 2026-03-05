/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:36:31 by acastald          #+#    #+#             */
/*   Updated: 2026/01/14 11:00:28 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_print_char(char c)
{
	unsigned char	au;

	au = (unsigned char)c;
	return (write(1, &au, 1));
}

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	nptr;
	int					len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	nptr = (unsigned long long)ptr;
	len = 0;
	len += write(1, "0x", 2);
	len += ft_print_hex(nptr, 'x');
	return (len);
}

int	ft_print_hex(unsigned long long nb, char c)
{
	int		len;
	char	*low;
	char	*up;

	len = 0;
	low = "0123456789abcdef";
	up = "0123456789ABCDEF";
	if (nb >= 16)
		len += ft_print_hex((nb / 16), c);
	if (c == 'x')
		len += write(1, &low[nb % 16], 1);
	if (c == 'X')
		len += write(1, &up[nb % 16], 1);
	return (len);
}
