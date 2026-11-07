/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:38:04 by acastald          #+#    #+#             */
/*   Updated: 2026/11/07 15:35:38 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <bits/time.h>

long	get_time_ms(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((ts.tv_sec * 1000) + (ts.tv_nsec / 1000000));
}

long	timestamp(t_info *info)
{
	long	log;

	log = get_time_ms() - info->start_time;
	return (log);
}
