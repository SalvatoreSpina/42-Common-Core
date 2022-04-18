/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:53:04 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 18:59:52 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

static bool	checker_is_redirection(t_token *t)
{
	return (t->type == DRC || t->type == LC
		|| t->type == RC || t->type == HEREDOCS);
}

static bool	checker_is_good_continuity(t_list *toks)
{
	t_token	*t;
	t_token	*n;

	t = (t_token *) toks->content;
	if (toks->next)
		n = (t_token *) toks->next->content;
	else
		n = NULL;
	if (t->type == RPAR && (n && (n->type != LOGICAL_OR
				&& n->type != LOGICAL_AND && n->type != RPAR)))
		return (false);
	if (checker_is_redirection(t) && (!n || n->type != ESCAPED_STRING))
		return (false);
	if (t->type == PIPE && (!n || (n->type != ESCAPED_STRING
				&& !checker_is_redirection(n))))
		return (false);
	if ((t->type == LOGICAL_AND || t->type == LOGICAL_OR
			|| t->type == LPAR) && (!n || (n->type != ESCAPED_STRING
				&& n->type != LPAR && !checker_is_redirection(n))))
		return (false);
	if (t->type == ESCAPED_STRING && n && n->type == LPAR)
		return (false);
	return (true);
}

static bool	check_parenthesis(t_list *toks)
{
	t_token	*t;
	int		open_count;

	open_count = 0;
	while (toks)
	{
		t = (t_token *) toks->content;
		if (t->type == LPAR)
			open_count++;
		if (t->type == RPAR)
			open_count--;
		toks = toks->next;
	}
	return (open_count == 0);
}

static bool	checker_has_command(t_list *current_tok)
{
	bool	has_cmd;

	has_cmd = false;
	while (current_tok)
	{
		if (((t_token *)((current_tok)->content))->type == ESCAPED_STRING)
			has_cmd = true;
		else if (checker_is_redirection((t_token *) current_tok->content))
			current_tok = current_tok->next;
		if (((t_token *)((current_tok)->content))->type == LOGICAL_AND
			|| ((t_token *)((current_tok)->content))->type == LOGICAL_OR
			|| ((t_token *)((current_tok)->content))->type == PIPE)
		{
			if (!has_cmd)
				return (false);
			has_cmd = false;
		}
		current_tok = current_tok->next;
	}
	return (has_cmd);
}

/* TODO: Check first tokens so && f or < file don;t crash */
bool	checker_is_valid(t_list *toks)
{
	t_list	*back;
	bool	first;

	back = toks;
	first = true;
	while (toks)
	{
		if (first)
		{
			if (((t_token *) toks->content)->type != ESCAPED_STRING
				&& ((t_token *) toks->content)->type != LPAR
				&& !checker_is_redirection((t_token *) toks->content))
				return (false);
			first = false;
		}
		if (!checker_is_good_continuity(toks))
			return (false);
		toks = toks->next;
	}
	return (checker_has_command(back) && check_parenthesis(back));
}
