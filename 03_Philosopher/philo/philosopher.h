/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:25:10 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:11 by sspina           ###   ########.fr       */
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

typedef struct s_table
{
	pthread_mutex_t	*fork;
}				t_table;

typedef struct s_philo
{
	int				philo_id;
	int				state;
	int				left_fork;
	int				right_fork;
	unsigned long	birth_time;
	long			sleep_time;
	long			eat_time;
	long			die_time;
	unsigned long	recent_meal;
	int				meal_size;
	pthread_t		thread;
	t_table			*table;
	pthread_mutex_t	*pronounce_dead;
	pthread_mutex_t	*meal_count;
	pthread_mutex_t	*meal_time;
}				t_philo;

typedef struct s_settings
{
	int				philo_size;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				meal_size;
	unsigned long	start_time;
	pthread_t		checker;
	t_philo			*philo;
	pthread_mutex_t	pronounce_dead;
	pthread_mutex_t	meal_count;
	pthread_mutex_t	meal_time;
}				t_settings;

int				init(t_settings *settings, char **argv);
unsigned long	timer(unsigned long birth_time);
unsigned long	get_current_time(void);
void			pass_time(unsigned long current_time, unsigned long time);
int				ft_atoi(const char *str);
void			fake_printf(t_philo philo, char *str);
void			*checker(void *arg);
void			no_leaks_please(t_settings *settings);
int				eat(t_philo *philo, t_table *table);
void			go_sleep(t_philo *philo, int sleep_time);
void			fake_printf_user(int code);
int				check_input(t_settings *settings, char **argv);

#endif
