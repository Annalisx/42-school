/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:30:30 by acastald          #+#    #+#             */
/*   Updated: 2025/11/27 19:32:07 by acastald         ###   ########.fr       */
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

/* int main()
{
    char str[] = "ciao baby";
    int i = 0;
    ft_bzero((void*)str, 5);
    while (i < 9)
    {
        if (!str[i])
            printf("index= %i\n", i);
        else
            i = 10;
        i++;
    }
} */