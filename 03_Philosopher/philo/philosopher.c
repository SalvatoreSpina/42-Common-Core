/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:46:33 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:56 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void	*routine(void *arg)
{
	t_philo		*philo;
	t_table		*table;

	philo = (t_philo *)arg;
	table = philo->table;
	while ("Sasso is awesome")
	{
		if (pthread_mutex_lock(philo->pronounce_dead))
			break ;
		if (philo->state == DEAD)
		{
			if (pthread_mutex_unlock(philo->pronounce_dead))
				break ;
			break ;
		}
		if (pthread_mutex_unlock(philo->pronounce_dead))
			break ;
		if (eat(philo, table) == ERROR)
			break ;
		if (!philo->meal_size || philo->right_fork == philo->left_fork)
			return (NULL);
		go_sleep(philo, philo->sleep_time);
		fake_printf(*philo, "is thinking");
	}
	return (NULL);
}

void	threads_creator(t_settings *settings)
{
	int			i;
	pthread_t	*thread;
	t_philo		*philo;
	pthread_t	*t_checker;

	i = 0;
	t_checker = &settings->checker;
	while (i < settings->philo_size)
	{
		philo = &settings->philo[i];
		thread = &settings->philo[i].thread;
		if (pthread_create(thread, NULL, routine, philo))
			return ;
		pass_time(get_current_time(), 1);
		i++;
	}
	if (pthread_create(t_checker, NULL, checker, settings))
		return ;
}

int	main(int argc, char **argv)
{
	t_settings	settings;
	int			i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (init(&settings, argv) == OK)
		{
			threads_creator(&settings);
			while (i < settings.philo_size)
			{
				if (pthread_join(settings.philo[i].thread, NULL))
					return (ERROR);
				i++;
			}
			if (pthread_join(settings.checker, NULL))
				return (ERROR);
			no_leaks_please(&settings);
		}
	}
	else
		fake_printf_user(NOT_ENOUGH_ARGS);
}
