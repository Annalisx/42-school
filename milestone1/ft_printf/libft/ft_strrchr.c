/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:22:24 by acastald          #+#    #+#             */
/*   Updated: 2025/12/17 13:17:25 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/* int main(void)
{
    char    *str = "AbraCadabra";
    char    *risultato;
    int     c;

    c = 'r';
    risultato = ft_strrchr(str, c);
    if (risultato == &str[9])
        printf("ok \"%s\"", risultato);
    else
        printf("X\n");
    
    printf("\n");

    c = 'A';
    risultato = ft_strrchr(str, c);
    if (risultato == str)
        printf("ok \"%s\"", risultato);
    else
        printf("X\n");

    printf("\n");
} */