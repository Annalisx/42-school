/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:02:53 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:03:52 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb != 0 && size > __SIZE_MAX__ / nmemb)
		return (NULL);
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

/* int main(void)
{
    char *str = (char *)ft_calloc(10, sizeof(char));
    if (!str)
    {
        printf("KOKO\n");
		free(str);
    }
    printf("Stringa: '%s'\n", str);
    if (str[0] == '\0')
        printf("OK\n");
    else
        printf("KO\n"); 
} */
