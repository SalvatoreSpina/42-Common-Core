/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:22:09 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:01:14 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_isnumber(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_digit_string(char *n)
{
	int	i;
	int	has_digit;
	int	has_zero;
	int	has_two_signs;

	i = -1;
	has_digit = 0;
	has_zero = 0;
	has_two_signs = 0;
	while (n[++i])
	{
		if (_isnumber(n[i]) && n[i] != '0')
			has_digit = 1;
		if (n[i] == '0')
			has_zero = 1;
		if (n[i] == '-' || n[i] == '+')
			has_two_signs += 1;
		if (has_two_signs == 2)
			break ;
	}
	if (!i || (!has_digit && !has_zero) || (has_digit && !ft_atoi(n))
		|| has_two_signs == 2)
		return (0);
	return (1);
}

/* return (0) is never reached since exit is the last function called,
its there so the compiler doesnt complain about not having a return value */
int	mnsh_builtin_exit(t_minishell *mnsh, char **argv)
{
	int	code;

	(void) argv;
	(void) mnsh;
	if (argv[1] != NULL)
	{
		if (!is_digit_string(argv[1]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		if (argv[2] != NULL)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		code = ft_atoi(argv[1]);
		ft_putstr_fd("exit\n", 2);
		exit(code);
	}
	ft_putstr_fd("exit\n", 2);
	exit(0);
	return (0);
}
