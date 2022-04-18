/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:25:10 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:25 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define NOT_ENOUGH_ARGS 1
# define NEG_ZERO_INPUT 2
# define ALIVE 3
# define DEAD 4

# define LOCKED 0
# define ERROR -1
# define OK 5

# include <pthread.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				philo_id;
	int				philo_size;
	int				pid;
	unsigned long	birth_time;
	long			sleep_time;
	long			eat_time;
	long			die_time;
	unsigned long	recent_meal;
	int				meal_size;
	sem_t			*forks;
	sem_t			*state;
	sem_t			*pronounce_dead;
	sem_t			*meal_time;
}				t_philo;

typedef struct s_settings
{
	int				philo_size;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				meal_size;
	unsigned long	start_time;
	pthread_t		*checker;
	pthread_t		killer;
	t_philo			*philo;
	sem_t			*forks;
	sem_t			*state;
	sem_t			*pronounce_dead;
	sem_t			*meal_time;
}				t_settings;

void			fake_printf(t_philo philo, char *str);
int				ft_atoi(const char *str);
unsigned long	timer(unsigned long birth_time);
void			pass_time(unsigned long current_time, unsigned long time);
unsigned long	get_current_time(void);
int				init(t_settings *settings, char **argv);
void			*checker(void *arg);
void			*loop(t_philo *philo);
void			go_sleep(t_philo *philo, int sleep_time);
void			eat(t_philo *philo);
void			no_leaks_please(t_settings *settings);
void			fake_printf_user(int code);
int				check_input(t_settings *settings, char **argv);

#endif
