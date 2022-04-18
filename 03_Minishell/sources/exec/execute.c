/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:32:20 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 19:12:15 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"
#include "token.h"
#include <sys/wait.h>

static bool	can_execute_next_command(t_minishell *mnsh, t_token *tokens)
{
	return (tokens->type == PIPE
		|| (tokens->type == LOGICAL_OR && mnsh->exec.last_ret != 0)
		|| (tokens->type == LOGICAL_AND && mnsh->exec.last_ret == 0));
}

static void	skip_command(t_list **cur)
{
	while (*cur && ((t_token *)((*cur)->content))->type != RPAR
		&& ((t_token *)((*cur)->content))->type != LOGICAL_AND
		&& ((t_token *)((*cur)->content))->type != LOGICAL_OR
		&& ((t_token *)((*cur)->content))->type != PIPE)
	{
		if (((t_token *)((*cur)->content))->type == ESCAPED_STRING)
			*cur = (*cur)->next;
		else if (((t_token *)((*cur)->content))->type == HEREDOCS
			|| ((t_token *)((*cur)->content))->type == LC
			|| ((t_token *)((*cur)->content))->type == RC
			|| ((t_token *)((*cur)->content))->type == DRC)
			*cur = (*cur)->next->next;
	}
}

static bool	skip_parenthesis_if_par(t_list **tokens, bool *par)
{
	if (*par)
	{
		if (((t_token *)((*tokens)->content))->type == RPAR)
		{
			*par = false;
			*tokens = (*tokens)->next;
			return (true);
		}
	}
	return (false);
}

void	execute(t_minishell *mnsh, t_list **tokens, bool ex, bool first)
{
	bool		par;
	bool		can;

	par = false;
	if (((t_token *)((*tokens)->content))->type == LPAR)
	{
		par = true;
		*tokens = (*tokens)->next;
	}
	if (*tokens && ((t_token *)((*tokens)->content))->type == LPAR)
		execute(mnsh, tokens, ex, false);
	else if (ex)
		parser_get_and_run_command(mnsh, tokens);
	else
		skip_command(tokens);
	if (skip_parenthesis_if_par(tokens, &par) && !first)
		return ;
	if (*tokens && ((t_token *)((*tokens)->content))->type != RPAR)
	{
		can = can_execute_next_command(mnsh, (t_token *)(*tokens)->content);
		*tokens = (*tokens)->next;
		execute(mnsh, tokens, can && ex, false);
	}
	skip_parenthesis_if_par(tokens, &par);
}
