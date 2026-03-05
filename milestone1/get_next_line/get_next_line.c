/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:32:40 by acastald          #+#    #+#             */
/*   Updated: 2026/02/26 14:28:29 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
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
	free(s1);
	return (new);
}

char	*ft_cut(char *str)
{
	int		i;
	int		j;
	char	*mod;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	mod = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (!mod)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		mod[j++] = str[i++];
	free (str);
	return (mod[j] = '\0', mod);
}

char	*ft_read(int fd, char *str)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	if (!str)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
			free (str);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str || str[0] == '\0')
		return (free(str), NULL);
	new = ft_substr(str);
	str = ft_cut(str);
	return (new);
}

/* int main()
{
	int fd = open("prova.txt", O_RDONLY);
	char buffer[1024];
	int bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	printf("%d\n", bytes_read);
	printf("%s\n", buffer);
} */
int main()
{
	int fd = open("prova.txt", O_RDONLY);
	char	*line = get_next_line(0);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	close(fd);
}