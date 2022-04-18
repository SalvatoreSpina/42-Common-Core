/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:48:21 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:32:26 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

# include "minishell.h"

typedef struct s_environ
{
	char	*name;
	char	*value;
	bool	should_display_in_env;
}	t_environ;

void		mnsh_environ_init(t_minishell *mnsh, char **environ);
t_environ	*mnsh_environ_parse_from_string(char *env);
t_environ	*mnsh_environ_create(char *name, char *val, bool ed);
void		mnsh_environ_delete(void *environ);

t_environ	*mnsh_get_in_environ(t_minishell *mnsh, char *var_name);
void		mnsh_set_in_environ(t_minishell *mnsh, char *var_name,
				char *value, bool ed);
void		mnsh_unset_in_environ(t_minishell *mnsh, char *var_name);
char		**environ_build_envp(t_minishell *mnsh);

#endif