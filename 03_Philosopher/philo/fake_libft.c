/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:25:51 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:12 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	long	i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		if ((str[i] == '-') || (str[i] == '+'))
			i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * neg);
}

static int	ft_strncmp(const void *s1, const void *s2, size_t num)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i != num && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	fake_printf(t_philo philo, char *str)
{
	if (philo.state == ALIVE || !ft_strncmp(str, "died", 4))
		printf("%-5lu Philosopher %-5d %-20s\n",
			timer(philo.birth_time), philo.philo_id, str);
}

void	fake_printf_user(int code)
{
	if (code == NOT_ENOUGH_ARGS)
	{
		printf("Please input the following:\n");
		printf("./philo [number_of_philosophers] [time_to_die] ");
		printf("[time_to_eat] [time_to_sleep]\n");
	}
	else if (code == NEG_ZERO_INPUT)
	{
		printf("Please input values above zero\n");
	}
}
