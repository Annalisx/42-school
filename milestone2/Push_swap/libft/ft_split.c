/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:31:37 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:15:58 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char c, char const *s)
{
	int	w;
	int	i;
	int	count;

	w = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && w == 0)
		{
			w = 1;
			count++;
		}
		if (s[i] == c)
			w = 0;
		i++;
	}
	return (count);
}

static void	free_all(char **matrix, int j)
{
	while (j >= 0)
	{
		free(matrix[j]);
		j--;
	}
	matrix[0] = NULL;
	return ;
}

static int	fill_matrix(char **matrix, char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			len = 0;
			while (s[i + len] != c && s[i + len])
				len++;
			matrix[j] = ft_substr(s, i, len);
			if (!matrix[j])
				return (free_all(matrix, j), -1);
			j++;
			i += len;
		}
	}
	matrix[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(c, s);
	matrix = (char **)malloc(sizeof(char *) * (count + 1));
	if (!matrix)
		return (NULL);
	if (fill_matrix(matrix, s, c) == -1)
	{
		free(matrix);
		return (NULL);
	}
	return (matrix);
}

// int main()
// {
//     char *s = "~~~ciao~amore~~~~";
//     char c = '~';
// 	char **result = ft_split(s, c);
// 	int i = 0;
// 	if (!result)
// 	{
//     	printf("La matrice è NULL\n");
// 	}
// 	else
// 	{
//     	while (result[i] != NULL)
//    		{
//         	printf("Riga %d: %s\n", i, result[i]); 
//  	        i++;
//     	}
// 		while (--i >= 0)
// 			free(result[i]);
// 	}
// 	free(result);
// }
