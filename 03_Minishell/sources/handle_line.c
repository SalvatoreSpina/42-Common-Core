/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:49:27 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 18:59:57 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "token.h"
#include "lexer.h"
#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>

static bool	handle_process_exit(t_minishell *mnsh)
{
	int		status;
	int		pid;
	t_list	*processes;

	processes = mnsh->running_processes;
	pid = wait(&status);
	if (pid == -1)
		return (false);
	exec_set_exit_status(mnsh, status);
	while (processes)
	{
		if (((t_process_ctx *)(processes->content))->pid == pid)
		{
			ft_lstdelone_ptr(&(mnsh->running_processes), processes, free);
			break ;
		}
		processes = processes->next;
	}
	return (true);
}

void	handle_line(t_minishell *mnsh, char *line)
{
	t_list			*tokens;
	t_list			*dup;

	tokens = lexer(mnsh, line);
	if (!tokens)
		return ;
	ft_lstadd_front(&tokens, ft_lstnew(tok_new(LPAR, NULL)));
	ft_lstadd_back(&tokens, ft_lstnew(tok_new(RPAR, NULL)));
	dup = tokens;
	if (checker_is_valid(tokens))
	{
		execute(mnsh, &dup, true, true);
		while (1)
		{
			if (!handle_process_exit(mnsh))
				break ;
		}
		ft_lstclear(&(mnsh->running_processes), &free);
	}
	else
	{
		ft_putstr_fd("minishell: parser: please check input\n", 2);
		mnsh->exec.last_ret = 258;
	}
	ft_lstclear(&tokens, (void (*)(void *)) & token_free);
}
