/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:43:13 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 16:46:35 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "builtins.h"
#include "environ.h"
#include "minishell.h"
#include "token.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define BINARY_NOT_FOUND 127
#define FOLDER_OR_PERMISSIONS 126

void	exec_enable_redirs(t_minishell *mnsh, t_command *cmd)
{
	(void) mnsh;
	if (cmd->redirs[REDIR_IN] != -1)
	{
		close(STDIN_FILENO);
		dup2(cmd->redirs[REDIR_IN], REDIR_IN);
		close(cmd->redirs[REDIR_IN]);
	}
	if (cmd->redirs[REDIR_OUT] != -1)
	{
		close(STDOUT_FILENO);
		dup2(cmd->redirs[REDIR_OUT], REDIR_OUT);
		close(cmd->redirs[REDIR_OUT]);
	}
}

void	exec_revert_redirs(t_minishell *mnsh, t_command *cmd)
{
	if (cmd->redirs[REDIR_IN] != -1)
		dup2(mnsh->save_stdin, STDIN_FILENO);
	if (cmd->redirs[REDIR_OUT] != -1)
		dup2(mnsh->save_stdout, STDOUT_FILENO);
}

void	exec_set_exit_status(t_minishell *mnsh, int status)
{
	if (WIFEXITED(status))
		mnsh->exec.last_ret = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		mnsh->exec.last_ret = 128 + WTERMSIG(status);
	else if (WIFSTOPPED(status))
		mnsh->exec.last_ret = 128 + WSTOPSIG(status);
}

void	exec_wait_if_not_piped(t_minishell *mnsh, bool piped, int pid)
{
	int	st;

	if (!piped)
	{
		waitpid(pid, &st, 0);
		exec_set_exit_status(mnsh, st);
	}
}

void	exec_try_run_forked_command(t_minishell *mnsh, t_command *cmd)
{
	char	binary_path[4096];
	char	**envp;
	int		result;

	result = 0;
	ft_bzero(binary_path, 4096);
	exec_enable_redirs(mnsh, cmd);
	if (find_builtin(cmd->argv[0]))
		exit(find_builtin(cmd->argv[0])(mnsh, cmd->argv));
	else if (find_in_path(mnsh, cmd->argv[0], binary_path))
		find_in_path(mnsh, cmd->argv[0], binary_path);
	else if (is_path(cmd->argv[0]))
		ft_strcpy(binary_path, cmd->argv[0]);
	else
	{
		fsf("minishell: %s: %s\n", cmd->argv[0], no_file_or_bin(cmd->argv[0]));
		exit(BINARY_NOT_FOUND);
	}
	envp = environ_build_envp(mnsh);
	result = execve(binary_path, cmd->argv, envp);
	if (result == -1)
	{
		fsf("minishell: %s: %s\n", cmd->argv[0], folder_or_perm(binary_path));
		exit(FOLDER_OR_PERMISSIONS);
	}
}
