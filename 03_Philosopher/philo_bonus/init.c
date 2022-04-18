/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:26:21 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:11 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>

static void	init_philo(t_settings *settings)
{
	int		i;

	i = 0;
	while (i < settings->philo_size)
	{
		settings->philo[i].philo_id = i + 1;
		settings->philo[i].philo_size = settings->philo_size;
		settings->philo[i].state = settings->state;
		settings->philo[i].recent_meal = 0;
		settings->philo[i].sleep_time = settings->sleep_time;
		settings->philo[i].die_time = settings->die_time;
		settings->philo[i].eat_time = settings->eat_time;
		settings->philo[i].birth_time = settings->start_time;
		settings->philo[i].meal_size = settings->meal_size;
		settings->philo[i].forks = settings->forks;
		settings->philo[i].state = settings->state;
		settings->philo[i].pronounce_dead = settings->pronounce_dead;
		settings->philo[i].meal_time = settings->meal_time;
		i++;
	}
}

int	init(t_settings *settings, char **argv)
{
	settings->philo_size = ft_atoi(argv[1]);
	settings->start_time = get_current_time();
	settings->die_time = ft_atoi(argv[2]);
	settings->eat_time = ft_atoi(argv[3]);
	settings->sleep_time = ft_atoi(argv[4]);
	settings->meal_size = -1;
	if (argv[5])
		settings->meal_size = ft_atoi(argv[5]);
	if (check_input(settings, argv) == ERROR)
		return (ERROR);
	settings->checker = malloc(sizeof(pthread_t) * settings->philo_size);
	settings->philo = malloc(sizeof(t_philo) * settings->philo_size);
	if (!settings->checker || !settings->philo)
		return (ERROR);
	sem_unlink("forks");
	sem_unlink("state");
	sem_unlink("pronounce dead");
	settings->forks = sem_open("forks", O_CREAT,
			0600, settings->philo_size);
	settings->state = sem_open("state", O_CREAT, 0600, LOCKED);
	settings->pronounce_dead = sem_open("pronounce dead", O_CREAT, 0600, 1);
	settings->meal_time = sem_open("meal time", O_CREAT, 0600, 1);
	init_philo(settings);
	return (OK);
}
