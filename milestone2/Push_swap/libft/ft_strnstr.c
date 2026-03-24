/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:41:35 by acastald          #+#    #+#             */
/*   Updated: 2025/11/27 20:02:12 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlittle;
	size_t	i;
	size_t	j;

	lenlittle = ft_strlen(little);
	if (big == little || lenlittle == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0'
			&& (i + j) < len && big[i + j] == little[j])
		{
			j++;
			if ((j == len && j == lenlittle) || j == lenlittle)
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}

/* int main()
{
	char big[] = "hello world!";
	char l1[] = "world";
	char l2[] = "lo w";
	char l3[] = "xyz";

	size_t n1 = 12;
	size_t n2 = 5;
	size_t n3 = 20;
	
	printf("t1\n");
	printf("Cerca \"%s\" in \"%s\" entro %zu:\n", l1, big, n1);
	printf("ft_strnstr : %s\n", ft_strnstr(big, l1, n1));
	printf("strnstr : %s\n\n", strnstr(big, l1, n1));
	printf("t2\n");
	printf("Cerca \"%s\" in \"%s\" entro %zu:\n", l2, big, n1);
	printf("ft_strnstr : %s\n", ft_strnstr(big, l2, n1));
	printf("strnstr : %s\n\n", strnstr(big, l2, n1));
	printf("t3\n");
	printf("Cerca \"%s\" in \"%s\" entro %zu:\n", l1, big, n2);
	printf("ft_strnstr : %s\n", ft_strnstr(big, l1, n2));
	printf("strnstr : %s\n\n", strnstr(big, l1, n2));
	printf("t4\n");
	printf("Cerca \"%s\" in \"%s\" entro %zu:\n", l3, big, n3);
	printf("ft_strnstr : %s\n", ft_strnstr(big, l3, n3));
	printf("strnstr : %s\n\n", strnstr(big, l3, n3));
	printf("t5\n");
	printf("Cerca \"\" in \"%s\" entro %zu:\n", big, n3);
	printf("ft_strnstr : %s\n", ft_strnstr(big, "", n3));
	printf("strnstr : %s\n\n", strnstr(big, "", n3));
} */