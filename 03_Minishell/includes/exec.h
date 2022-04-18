/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 06:40:52 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:33:49 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# define REDIR_IN 0
# define REDIR_OUT 1

typedef enum e_redir_type
{
	IN = 1,
	HD = 2,
	OUT = 4,
	APPEND = 8,
}	t_redir_type;

// third argument is to know when to fork builtins
typedef struct s_command
{
	char	**argv;
	int		redirs[2];
	bool	piped_stdin;
	bool	piped_stdout;
}	t_command;

bool	is_path(char *str);
bool	find_in_path(t_minishell *mnsh, char *binary_name, char *dst);

void	exec_enable_redirs(t_minishell *mnsh, t_command *cmd);
void	exec_revert_redirs(t_minishell *mnsh, t_command *cmd);
void	exec_set_exit_status(t_minishell *mnsh, int status);
void	exec_wait_if_not_piped(t_minishell *mnsh, bool piped, int pid);
void	exec_try_run_forked_command(t_minishell *mnsh, t_command *cmd);
void	execute(t_minishell *mnsh, t_list **tokens, bool ex, bool first);

/* parser.c && parser_redir.c */
int		parser_get_redirs(t_minishell *mnsh, t_command *cmd, t_list *toks);
void	parser_handle_pipe_stuff(t_minishell *mnsh, t_command *cmd, bool piped);
void	parser_get_and_run_command(t_minishell *mnsh, t_list **toks);

typedef t_process_ctx	t_pctx;

/* process_ctx */
t_pctx	*make_pctx(int pid, int fdin, int fdout);

#endif