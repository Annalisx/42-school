/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:47:28 by acastald          #+#    #+#             */
/*   Updated: 2025/12/17 12:59:02 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

/* int main(void)
{
    char *s = "Ciao Mondo";
    char *res = ft_memchr(s, 'M', 10);
    if (res && *res == 'M')
        printf("ok\n");
    else
        printf("ko\n");

    if (ft_memchr(s, 'z', 10) == NULL)
        printf("ok\n");
    else
        printf("ko\n");
    return (0);
} */
