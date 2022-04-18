/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:27:08 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:26 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>

static int	ca_va(t_philo *philo)
{
	unsigned long	current_time;

	if (!philo->recent_meal)
		current_time = timer(philo->birth_time);
	else
		current_time = get_current_time();
	if (current_time >= philo->recent_meal + philo->die_time)
		return (DEAD);
	return (ALIVE);
}

void	*checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while ("Sasso is awesome")
	{
		if (!philo->meal_size && philo->philo_id == philo->philo_size)
		{
			sem_wait(philo->pronounce_dead);
			sem_post(philo->state);
			return (NULL);
		}
		if (ca_va(philo) == DEAD)
		{
			sem_wait(philo->pronounce_dead);
			fake_printf(*philo, "died");
			sem_post(philo->state);
			return (NULL);
		}
	}
	return (NULL);
}

int	check_input(t_settings *settings, char **argv)
{
	if (settings->philo_size <= 0 || settings->die_time <= 0
		|| settings->eat_time <= 0 || settings->sleep_time <= 0)
	{
		fake_printf_user(NEG_ZERO_INPUT);
		return (ERROR);
	}
	if (argv[5] && settings->meal_size <= 0)
	{
		fake_printf_user(NEG_ZERO_INPUT);
		return (ERROR);
	}
	return (OK);
}
