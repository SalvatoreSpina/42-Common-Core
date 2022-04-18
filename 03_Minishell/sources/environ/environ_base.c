/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:42:01 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:00:49 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "environ.h"
#include <stdio.h>

void	mnsh_environ_init(t_minishell *mnsh, char **environ)
{
	t_list	*new;

	mnsh->environ = NULL;
	while (*environ)
	{
		new = ft_lstnew(mnsh_environ_parse_from_string(*environ));
		ft_lstadd_back(&mnsh->environ, new);
		environ++;
	}
}

t_environ	*mnsh_environ_parse_from_string(char *env)
{
	t_environ	*sspina;
	char		**pleberr;

	pleberr = ft_split(env, '=');
	sspina = ft_calloc(1, sizeof(t_environ));
	sspina->name = pleberr[0];
	sspina->value = pleberr[1];
	sspina->should_display_in_env = pleberr[1] != NULL;
	free(pleberr);
	return (sspina);
}

t_environ	*mnsh_environ_create(char *name, char *val, bool ed)
{
	t_environ	*env;

	env = ft_calloc(1, sizeof(t_environ));
	env->name = name;
	env->value = val;
	env->should_display_in_env = ed;
	return (env);
}

void	mnsh_environ_delete(void *environ)
{
	t_environ	*env;

	env = (t_environ *) environ;
	free(env->name);
	free(env->value);
	free(environ);
}
