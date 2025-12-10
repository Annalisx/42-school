/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:31:12 by acastald          #+#    #+#             */
/*   Updated: 2025/12/05 18:04:44 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*orig;

	if (!dest && !src)
		return (0);
	if (n == 0 || (dest == src))
		return (dest);
	dst = (char *)dest;
	orig = (const char *)src;
	while (n != 0)
	{
		if (*dst != *orig)
			*dst = *orig;
		dst++;
		orig++;
		n--;
	}
	return (dest);
}

//int main()