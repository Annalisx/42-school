/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:30:30 by acastald          #+#    #+#             */
/*   Updated: 2025/12/19 15:08:03 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n != 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

/* int main(void)
{
    char str[] = "Ciao baby";
    int size = 10;
    
    //bzero(str, 5);
    //ft_bzero(str, 5);
    
    int i = 0;
    while (i < size)
    {
        unsigned char c = (unsigned char)str[i];
        if (c >= 32 && c <= 126)
            printf("'%c' ", c);
        else if (c == 0)
            printf("\\0 ");
        else
            printf("?? ");
        i++;
    }
    printf("\n");
    return (0);
} */
