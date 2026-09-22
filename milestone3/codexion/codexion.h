/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annalisacastaldo <annalisacastaldo@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:37:23 by acastald          #+#    #+#             */
/*   Updated: 2026/09/22 15:45:19 by annalisacas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# define RED "\033[2;31m"
# define RESET "\x1b[0m"

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_info
{
	int		number_of_coders;
	long	time_to_burnout;
	long	time_to_compile;
	long	time_to_debug;
	long	time_to_refactor;
	int		number_of_compiles_required;
	long	dongle_cooldown;
	int		algo;
}	t_info;

typedef struct s_dongles
{
	int		dongle_id;
	bool	active;
}	t_dongles;

typedef struct s_coders
{
	int					coder_id;
	struct s_dongles	*left;
	struct s_dongles	*right;
	struct s_coders		*next;
	struct s_coders		*prev;
}	t_coders;

int			pars_scheduler(t_info *type, char *str);
t_coders	*numbers_of_coders(long num_coders);
void		print_error(int error);
int			init_s_info(t_info *info, char **av);
int			check(char *str);
long		ft_atol(char *nptr);

#endif
