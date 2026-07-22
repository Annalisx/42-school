/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:37:23 by acastald          #+#    #+#             */
/*   Updated: 2026/07/22 11:13:19 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_list
{
	int				number_of_coders;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	int				number_of_compiles_required;
	long			dongle_cooldown;
	struct s_list	*scheduler;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

#endif
