/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:59:41 by acastald          #+#    #+#             */
/*   Updated: 2026/01/20 16:07:47 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conv(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(arg, int));
	else if (c == 's')
		len += ft_print_str(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_print_ptr(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		len += ft_print_nbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_print_unbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(arg, unsigned int), c);
	else if (c == '%')
		len += ft_print_char('%');
	else
		return (0);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	if (!str)
		return (-1);
	i = 0;
	len = 0;
	va_start (arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 32 || str[i] == 0)
				return (0);
			len += ft_check_conv(str[i], arg);
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

/* int main()
{
	ft_printf("c - %c\n", 'A');

	ft_printf("s - %s\n", "Ciao 42");
	
	ft_printf("d / i - %d, %i\n", 42, -1234);

	ft_printf("u - %u\n", 3000000000U);
	
	ft_printf("x / X - %x (low) - %X (up)\n", 255, 255);
	
	int a = 42;
	ft_printf("p - %p\n", &a);
	
	ft_printf("percentuale - %%\n");
} */