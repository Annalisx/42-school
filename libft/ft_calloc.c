/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:02:53 by acastald          #+#    #+#             */
/*   Updated: 2025/12/07 13:55:22 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	int		i;
	void	*s;
	
	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb * size > __INT_MAX__)
		return ((void *)1);
	s = (void*)malloc(sizeof(nmemb * size));
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

int main(void)
{
	
	return (0);
}