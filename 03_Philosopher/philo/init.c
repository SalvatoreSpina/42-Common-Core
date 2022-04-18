/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:26:21 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:12 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>

static int	init_forks(t_settings *settings, t_table *table)
{
	int	i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * settings->philo_size);
	if (!table->fork)
		return (ERROR);
	while (i < settings->philo_size)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return (ERROR);
		i++;
	}
	return (OK);
}

static int	init_philo(t_settings *settings)
{
	int		i;
	t_table	*table;

	i = 0;
	table = malloc(sizeof(t_table));
	if (!table || init_forks(settings, table) == ERROR)
		return (ERROR);
	while (i < settings->philo_size)
	{
		settings->philo[i].philo_id = i + 1;
		settings->philo[i].state = ALIVE;
		settings->philo[i].left_fork = (i + 1) % settings->philo_size;
		settings->philo[i].right_fork = i;
		settings->philo[i].table = table;
		settings->philo[i].sleep_time = settings->sleep_time;
		settings->philo[i].die_time = settings->die_time;
		settings->philo[i].eat_time = settings->eat_time;
		settings->philo[i].birth_time = settings->start_time;
		settings->philo[i].meal_size = settings->meal_size;
		settings->philo[i].pronounce_dead = &settings->pronounce_dead;
		settings->philo[i].meal_count = &settings->meal_count;
		settings->philo[i].meal_time = &settings->meal_time;
		i++;
	}
	return (OK);
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
	if (pthread_mutex_init(&settings->pronounce_dead, NULL) != 0
		|| pthread_mutex_init(&settings->meal_count, NULL) != 0
		|| pthread_mutex_init(&settings->meal_time, NULL) != 0)
		return (ERROR);
	settings->philo = malloc(sizeof(t_philo) * settings->philo_size);
	if (!settings->philo || init_philo(settings) == ERROR)
		return (ERROR);
	return (OK);
}
