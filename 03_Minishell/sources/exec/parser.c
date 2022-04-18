/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:42:04 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:27:16 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include "token.h"
#include "minishell.h"
#include "exec.h"
#include "builtins.h"

static int	parser_get_argv_length(t_minishell *mnsh, t_list *current_tok)
{
	int				argv_length;

	(void) mnsh;
	argv_length = 0;
	while (current_tok && ((t_token *)((current_tok)->content))->type != RPAR
		&& ((t_token *)((current_tok)->content))->type != LOGICAL_AND
		&& ((t_token *)((current_tok)->content))->type != LOGICAL_OR
		&& ((t_token *)((current_tok)->content))->type != PIPE)
	{
		if (((t_token *)((current_tok)->content))->type == ESCAPED_STRING)
		{
			current_tok = current_tok->next;
			argv_length++;
		}
		else if (((t_token *)((current_tok)->content))->type == HEREDOCS
			|| ((t_token *)((current_tok)->content))->type == LC
			|| ((t_token *)((current_tok)->content))->type == RC
			|| ((t_token *)((current_tok)->content))->type == DRC)
			current_tok = current_tok->next->next;
	}
	return (argv_length);
}

static char	**parser_get_argv(t_minishell *mnsh, t_list **toks)
{
	t_list			*current_tok;
	char			**argv;
	int				argv_idx;

	argv = ft_calloc(parser_get_argv_length(mnsh, *toks) + 1, sizeof(char *));
	if (!argv)
	{
		ft_putstr_fd("minishell: fatal error: malloc failed\n", 2);
		exit(1);
	}
	argv_idx = 0;
	current_tok = *toks;
	while (current_tok && ((t_token *)(current_tok->content))->type != RPAR
		&& ((t_token *)(current_tok->content))->type != LOGICAL_AND
		&& ((t_token *)(current_tok->content))->type != LOGICAL_OR
		&& ((t_token *)(current_tok->content))->type != PIPE)
	{
		if (((t_token *)(current_tok->content))->type == ESCAPED_STRING)
			argv[argv_idx++] = ((t_token *)((current_tok)->content))->data;
		else
			*toks = (*toks)->next;
		*toks = (*toks)->next;
		current_tok = *toks;
	}
	return (argv);
}

// TODO: Should do wait is not piped when (echo | cat) && ls
static void	parser_run_command(t_minishell *mnsh, t_command *cmd, int pid)
{
	if (find_builtin(cmd->argv[0]) && !cmd->piped_stdin && !cmd->piped_stdout)
	{
		exec_enable_redirs(mnsh, cmd);
		mnsh->exec.last_ret = find_builtin(cmd->argv[0])(mnsh, cmd->argv);
		exec_revert_redirs(mnsh, cmd);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			exit(ft_putstr_fd("minishell: fatal: couldn't fork\n", 2));
		else if (pid == 0)
		{
			close(mnsh->exec.stdin_fd);
			exec_try_run_forked_command(mnsh, cmd);
		}
		else
		{
			ft_lstadd_back(&(mnsh->running_processes),
				ft_lstnew(make_pctx(pid, cmd->redirs[0], cmd->redirs[1])));
			close_mult(2, (int [2]){cmd->redirs[0], cmd->redirs[1]});
			exec_wait_if_not_piped(mnsh, cmd->piped_stdout, pid);
		}
	}
}

static bool	parser_is_command_piped(t_list *toks)
{
	while (toks && ((t_token *)(toks->content))->type != RPAR
		&& ((t_token *)(toks->content))->type != LOGICAL_AND
		&& ((t_token *)(toks->content))->type != LOGICAL_OR
		&& ((t_token *)(toks->content))->type != PIPE)
	{
		if (((t_token *)(toks->content))->type == ESCAPED_STRING)
			toks = toks->next;
		else
			toks = toks->next->next;
	}
	return (toks && ((t_token *)(toks->content))->type == PIPE);
}

void	parser_get_and_run_command(t_minishell *mnsh, t_list **toks)
{
	bool		exec;
	t_command	cmd;

	exec = 1;
	cmd.argv = NULL;
	cmd.redirs[0] = -1;
	cmd.redirs[1] = -1;
	cmd.piped_stdin = false;
	cmd.piped_stdout = false;
	parser_handle_pipe_stuff(mnsh, &cmd, parser_is_command_piped(*toks));
	if (parser_get_redirs(mnsh, &cmd, *toks))
		exec = 0;
	cmd.argv = parser_get_argv(mnsh, toks);
	if (exec)
		parser_run_command(mnsh, &cmd, -1);
	free(cmd.argv);
}
