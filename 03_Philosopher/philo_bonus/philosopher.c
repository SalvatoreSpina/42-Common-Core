/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:46:33 by sspina            #+#    #+#             */
/*   Updated: 2021/12/14 14:46:35 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void	kill_process(void *arg)
{
	t_settings	*settings;
	int			i;

	i = 0;
	settings = (t_settings *)arg;
	sem_wait(settings->state);
	while (i < settings->philo_size)
	{
		kill(settings->philo[i].pid, SIGKILL);
		i++;
	}
}

void	close_semaphore(t_settings *settings)
{
	sem_close(settings->forks);
	sem_close(settings->state);
	sem_close(settings->pronounce_dead);
	sem_close(settings->meal_time);
	sem_unlink("forks");
	sem_unlink("state");
	sem_unlink("pronounce dead");
	sem_unlink("meal time");
}

void	start_children(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->philo_size)
	{
		settings->philo[i].pid = fork();
		if (i > 0)
			pass_time(get_current_time(), 3);
		if (settings->philo[i].pid == 0)
		{
			if (pthread_create(&settings->checker[i], NULL,
					checker, &settings->philo[i]))
				exit(1);
			loop(&settings->philo[i]);
		}
		i++;
	}
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
			start_children(&settings);
			while (i < settings.philo_size)
			{
				if (pthread_join(settings.checker[i], NULL))
					break ;
				i++;
			}
			kill_process(&settings);
			close_semaphore(&settings);
			no_leaks_please(&settings);
		}
	}
	else
		fake_printf_user(NOT_ENOUGH_ARGS);
}
