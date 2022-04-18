/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:09:16 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:00:55 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

static const t_builtin	g_builtins[] = {
{"env", &mnsh_builtin_env},
{"cd", &mnsh_builtin_cd},
{"pwd", &mnsh_builtin_pwd},
{"export", &mnsh_builtin_export},
{"xkp", &mnsh_builtin_export},
{"unset", &mnsh_builtin_unset},
{"echo", &mnsh_builtin_echo},
{"hecho", &mnsh_builtin_echo},
{"exit", &mnsh_builtin_exit},
{"sspina", &mnsh_builtin_sspina},
{NULL, NULL}
};

t_builtin_func	find_builtin(char *name)
{
	const t_builtin	*curr;

	curr = g_builtins;
	while (curr->name)
	{
		if (!ft_strcmp(curr->name, name))
			return (curr->func);
		curr++;
	}
	return (NULL);
}
