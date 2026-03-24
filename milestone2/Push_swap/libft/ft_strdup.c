/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:29:03 by acastald          #+#    #+#             */
/*   Updated: 2026/01/23 10:20:35 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!s)
		return (NULL);
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/* int main()
{ 
	char *og = "ei come va";
	char *dup = ft_strdup(og);
	if (dup != NULL)
	{
		printf("%s\n", dup);
		free (dup);
	}
	else
		printf("NULL");
}  */