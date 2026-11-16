/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annalisacastaldo <annalisacastaldo@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:53:38 by acastald          #+#    #+#             */
/*   Updated: 2026/11/10 20:13:42 by annalisacas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compiling(t_coders *num_coder)
{
    print_msg(num_coder, "is compiling");
    usleep(num_coder->info->time_to_compile * 1000);
}

void	debugging(t_coders *num_coder)
{
    print_msg(num_coder, "is debugging");
    usleep(num_coder->info->time_to_debug * 1000);
}

void	refactoring(t_coders *num_coder)
{
    print_msg(num_coder, "is refactoring");
    usleep(num_coder->info->time_to_refactor * 1000);
}
