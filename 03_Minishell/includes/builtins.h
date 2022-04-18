/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:21:09 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:28:35 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef int	(*t_builtin_func)(t_minishell *mnsh, char **argv);
typedef struct s_builtin
{
	char			*name;
	t_builtin_func	func;
}	t_builtin;

t_builtin_func	find_builtin(char *name);
int				mnsh_builtin_env(t_minishell *mnsh, char **argv);
int				mnsh_builtin_cd(t_minishell *mnsh, char **argv);
int				mnsh_builtin_pwd(t_minishell *mnsh, char **argv);
int				mnsh_builtin_export(t_minishell *mnsh, char **argv);
int				mnsh_builtin_unset(t_minishell *mnsh, char **argv);
int				mnsh_builtin_echo(t_minishell *mnsh, char **argv);
int				mnsh_builtin_exit(t_minishell *mnsh, char **argv);
int				mnsh_builtin_sspina(t_minishell *mnsh, char **argv);

#endif