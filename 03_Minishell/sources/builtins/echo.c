/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:28:25 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:01:04 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_no_nl(char *hihi)
{
	if (*hihi == '-')
	{
		while (*(++hihi))
		{
			if (*hihi != 'n')
				return (0);
		}
		return (1);
	}
	return (0);
}

int	mnsh_builtin_echo(t_minishell	*mnsh, char **argv)
{
	bool	newline;
	int		i;

	(void) mnsh;
	i = 1;
	newline = true;
	while (argv[i] && is_valid_no_nl(argv[i]))
	{
		i++;
		newline = false;
	}
	while (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
	return (0);
}
