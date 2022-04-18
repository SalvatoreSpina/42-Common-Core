/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:25:32 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:56 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	one_fork(t_philo *philo, t_table *table)
{
	if (pthread_mutex_lock(&table->fork[philo->right_fork]) == LOCKED)
		fake_printf(*philo, "has taken a fork");
	else
		return (ERROR);
	return (OK);
}

static int	search_fork(t_philo *philo, t_table *table)
{
	if (philo->left_fork == philo->right_fork)
		return (one_fork(philo, table));
	if (philo->philo_id % 2 == 0)
	{
		if (pthread_mutex_lock(&table->fork[philo->right_fork]) == LOCKED)
			fake_printf(*philo, "has taken a fork");
		else
			return (ERROR);
		if (pthread_mutex_lock(&table->fork[philo->left_fork]) == LOCKED)
			fake_printf(*philo, "has taken a fork");
		else
			return (ERROR);
	}
	else
	{
		if (pthread_mutex_lock(&table->fork[philo->left_fork]) == LOCKED)
			fake_printf(*philo, "has taken a fork");
		else
			return (ERROR);
		if (pthread_mutex_lock(&table->fork[philo->right_fork]) == LOCKED)
			fake_printf(*philo, "has taken a fork");
		else
			return (ERROR);
	}
	return (OK);
}

int	eat(t_philo *philo, t_table *table)
{
	if (search_fork(philo, table) == ERROR)
		return (ERROR);
	if (philo->left_fork == philo->right_fork)
		pthread_mutex_unlock(&table->fork[philo->right_fork]);
	else
	{
		if (pthread_mutex_lock(philo->meal_time))
			return (ERROR);
		philo->recent_meal = get_current_time();
		if (pthread_mutex_unlock(philo->meal_time))
			return (ERROR);
		fake_printf(*philo, "is eating");
		if (pthread_mutex_lock(philo->meal_count))
			return (ERROR);
		philo->meal_size--;
		if (pthread_mutex_unlock(philo->meal_count))
			return (ERROR);
		pass_time(get_current_time(), philo->eat_time);
		if (pthread_mutex_unlock(&table->fork[philo->left_fork])
			|| pthread_mutex_unlock(&table->fork[philo->right_fork]))
			return (ERROR);
	}
	return (OK);
}

void	go_sleep(t_philo *philo, int sleep_time)
{
	fake_printf(*philo, "is sleeping");
	pass_time(get_current_time(), sleep_time);
}
