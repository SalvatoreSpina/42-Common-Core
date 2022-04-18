/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leak_please.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:25:58 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:18 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>

void	free_fork(int size, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(&fork[i]))
			break ;
		i++;
	}
	free(fork);
}

void	no_leaks_please(t_settings *settings)
{
	free_fork(settings->philo_size, settings->philo->table->fork);
	free(settings->philo->table);
	pthread_mutex_destroy(&settings->pronounce_dead);
	pthread_mutex_destroy(&settings->meal_count);
	pthread_mutex_destroy(&settings->meal_time);
	free(settings->philo);
}
