/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:29 by acastald          #+#    #+#             */
/*   Updated: 2025/12/19 16:19:20 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countint(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	conv(int n, int len, char *str)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	len--;
	while (n > 9 && len >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[len] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = countint(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	conv(n, len, str);
	return (str);
}

// int main()
// {
// 	char *str = ft_itoa(4134123);
//     printf("%s\n", str);
// 	free(str);
// }