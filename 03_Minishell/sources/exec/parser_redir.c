/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:36:35 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:20:16 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <fcntl.h>
#include "token.h"
#include "minishell.h"
#include "exec.h"

#include <errno.h>

static int	parser_handle_heredocs(t_minishell *mnsh, char *end_word)
{
	char	*line;
	int		fds[2];

	if (1 && mnsh)
		pipe(fds);
	while (1 && mnsh)
	{
		line = readline("heredocs> ");
		if (!line || !ft_strcmp(end_word, line))
		{
			free(line);
			break ;
		}
		write(fds[1], line, ft_strlen(line));
		write(fds[1], "\n", 1);
		free(line);
	}
	close(fds[1]);
	return (fds[0]);
}

// pipe following and pipe before too
void	parser_handle_pipe_stuff(t_minishell *mnsh, t_command *cmd, bool piped)
{
	int	fds[2];

	if (mnsh->exec.stdin_fd != -1)
	{
		cmd->redirs[REDIR_IN] = mnsh->exec.stdin_fd;
		cmd->piped_stdin = true;
		mnsh->exec.stdin_fd = -1;
	}
	if (piped)
	{
		pipe(fds);
		mnsh->exec.stdin_fd = fds[0];
		cmd->piped_stdout = true;
		cmd->redirs[REDIR_OUT] = fds[1];
	}
}

static void	parser_new_redir(t_command *cmd, int redir, int fd)
{
	if (cmd->redirs[redir] != -1)
		close(cmd->redirs[redir]);
	cmd->redirs[redir] = fd;
}

static int	parser_setup_redir(t_minishell *mnsh, t_command *cmd,
	t_redir_type type, char *param)
{
	int	fd;

	if (type == IN || type == HD)
	{
		if (type == HD)
			fd = parser_handle_heredocs(mnsh, param);
		else
			fd = open(param, O_RDONLY | O_CLOEXEC);
		if (fd == -1)
			return (fsf("minishell: %s: %s\n", param, strerror(errno)));
		parser_new_redir(cmd, REDIR_IN, fd);
	}
	if (type == OUT || type == APPEND)
	{
		if (type == OUT)
			fd = open(param, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else
			fd = open(param, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			return (fsf("minishell: %s: %s\n", param, strerror(errno)));
		parser_new_redir(cmd, REDIR_OUT, fd);
	}
	return (0);
}

int	parser_get_redirs(t_minishell *mnsh, t_command *cmd, t_list *toks)
{
	while (toks && ((t_token *)(toks->content))->type != RPAR
		&& ((t_token *)(toks->content))->type != LOGICAL_AND
		&& ((t_token *)(toks->content))->type != LOGICAL_OR
		&& ((t_token *)(toks->content))->type != PIPE)
	{
		if (((t_token *)(toks->content))->type == LC
			|| ((t_token *)(toks->content))->type == RC
			|| ((t_token *)(toks->content))->type == DRC
			|| ((t_token *)(toks->content))->type == HEREDOCS)
		{
			if (parser_setup_redir(mnsh, cmd,
					(t_redir_type)((t_token *)(toks->content))->type,
					((t_token *)(toks->next->content))->data))
				return (1);
			toks = toks->next;
		}
		toks = toks->next;
	}
	return (0);
}
