/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:03:01 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:01:00 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mnsh_builtin_cd(t_minishell *mnsh, char **argv)
{
	(void) mnsh;
	if (argv[1] != NULL)
	{
		if (chdir(argv[1]) == -1)
		{
			perror("minishell: cd");
			return (1);
		}
		else
			return (0);
	}
	else
	{
		ft_putstr_fd("minishell: cd: expected a path\n", 2);
		return (1);
	}
}
