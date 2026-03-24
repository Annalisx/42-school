/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:32:45 by acastald          #+#    #+#             */
/*   Updated: 2026/01/23 10:20:42 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[len1 + len2] = '\0';
	return (new);
}

/* int main()
{
	char *s1 = "coco";
	char *s2 = "mero"; 
	char *new = ft_strjoin(s1, s2);
	printf("%s\n", new);
} */