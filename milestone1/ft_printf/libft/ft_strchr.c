/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:19:14 by acastald          #+#    #+#             */
/*   Updated: 2026/01/23 10:21:01 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (ch == '\0')
	{
		i = ft_strlen(s);
		return ((char *)s + i++);
	}
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/* int main(void)
{
    int     c = 'o';
    char    *str = "Mondo 42";
    char    *risultato = ft_strchr(str, c);
	
    if (risultato) 
        printf("%s\n", risultato);
    else
	{
        printf("XXX\n");
	}
	c = '\0';
    risultato = ft_strchr(str, c);
    if (risultato)
        printf("ok\n");
    else
        printf("XXX\n");
} */