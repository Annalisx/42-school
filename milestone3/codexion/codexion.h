/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:37:23 by acastald          #+#    #+#             */
/*   Updated: 2026/07/23 17:59:19 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>

typedef struct s_coders
{
	int				coder_id;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	int				number_of_compiles_required;
	long			dongle_cooldown;
	int				algo;
	struct s_coders	*next;
	struct s_coders	*prev;
}	t_coders;

char	*ft_substr(char const *s, unsigned int start, size_t len);
static int	count_words(char c, char const *s);
static void	free_all(char **matrix, int j);
static int	fill_matrix(char **matrix, char const *s, char c);
char	**ft_split(char const *s, char c);


#endif
