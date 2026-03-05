/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:41:31 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 17:53:27 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (start >= end)
		return (ft_strdup(""));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	new = (char *)malloc(sizeof(char) * ((end + 1) - start) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		new[i++] = s1[start++];
	}
	new[i] = '\0';
	return (new);
}

/* int main()
{
	char s1[] = "012345067890";
	char *res = ft_strtrim(s1, "0");
	printf("%s\n", res);
	free(res);
} */
