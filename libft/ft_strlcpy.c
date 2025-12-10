/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:32:34 by acastald          #+#    #+#             */
/*   Updated: 2025/11/27 18:34:44 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (src[t])
		t++;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (t);
}

/* #include <string.h>
int main()
{
	unsigned int n = 2;
	char a[5];
	char b[8] = "Hi Anna";
	printf("the size of the string is %zu\n", ft_strlcpy(a, b, n));
	printf("dest: %s\n", a);
	printf("%zu\n", ft_strlcpy(a, b, n));
	printf("%zu\n", strlcpy(a, b, n));
} */