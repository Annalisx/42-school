/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:31:33 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 15:07:37 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = (const char *)src;
	d = (char *)dest;
	i = 0;
	if (d == s || n == 0)
		return (d);
	else if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (n > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

/* int main ()
{
    char source[] = "cio";
    char destination[] = "hello";
    size_t num = 7;
    printf("%s\n",  (char *)memmove(destination, source + 2, num));
    char sour[] = "cio";
    char destin[] = "hello";
    size_t nu = 7;
    printf("%s\n",  (char *)ft_memmove(destin, sour + 2, nu));
} */