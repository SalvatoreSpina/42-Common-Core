/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:25:32 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:18 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->forks);
	fake_printf(*philo, "has taken a fork");
	sem_wait(philo->forks);
	fake_printf(*philo, "has taken a fork");
	sem_wait(philo->meal_time);
	philo->recent_meal = get_current_time();
	sem_post(philo->meal_time);
	fake_printf(*philo, "is eating");
	if (philo->meal_size)
		philo->meal_size--;
	pass_time(get_current_time(), philo->eat_time);
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	go_sleep(t_philo *philo, int sleep_time)
{
	fake_printf(*philo, "is sleeping");
	pass_time(get_current_time(), sleep_time);
}

void	*loop(t_philo *philo)
{
	while ("Sasso is awesome")
	{
		eat(philo);
		go_sleep(philo, philo->sleep_time);
		fake_printf(*philo, "is thinking");
	}
	return (NULL);
}
