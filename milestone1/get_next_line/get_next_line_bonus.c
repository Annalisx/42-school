/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:33:26 by acastald          #+#    #+#             */
/*   Updated: 2026/02/18 16:20:20 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd] || str[fd][0] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	new = ft_substr(str[fd]);
	str[fd] = ft_cut(str[fd]);
	return (new);
}
/* 
int main(void)
{
    int     fd1;
    int     fd2;
    char    *line;
    int     i = 1;

    fd1 = open("prova.txt", O_RDONLY);
    fd2 = open("prova2.txt", O_RDONLY);

    while (i <= 3)
    {
        line = get_next_line(fd1);
        printf("[FD %d] Riga %d: %s", fd1, i, line);
        free(line);
        line = get_next_line(fd2);
        printf("[FD %d] Riga %d: %s", fd2, i, line);
        free(line);   
        i++;
    }
    line = get_next_line(fd1);
    if (line == NULL)
        printf("\n[FD %d] Fine file raggiunta correttamente.\n", fd1);
    free(line);
    close(fd1);
    close(fd2);
    return (0);
} */