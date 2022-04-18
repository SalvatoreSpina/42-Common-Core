/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:21:36 by achansel          #+#    #+#             */
/*   Updated: 2022/04/18 09:51:33 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "token.h"

/* Handles left parenthesis, right parenthesis, pipe,
	left chevron, right chevron, only go to next char
	if one of those was found */
static int	lexer_handle_special_char(t_list **tokens, const char **line)
{
	if (**line == '|' && *(*line + 1) != '|')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(PIPE, NULL)));
	else if (**line == '(')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(LPAR, NULL)));
	else if (**line == ')')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(RPAR, NULL)));
	else if (**line == '<' && *(*line + 1) != '<')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(LC, NULL)));
	else if (**line == '>' && *(*line + 1) != '>')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(RC, NULL)));
	else
		return (0);
	(*line)++;
	return (1);
}

/* Handles logical and, logical or,	heredocs and
	double right chevrons, only go to second next char
	if one of those was found */
static int	lexer_handle_special_chars(t_list **tokens, const char **line_ptr)
{
	const char	*line;

	line = *line_ptr;
	if (*line == '&' && *(line + 1) == '&')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(LOGICAL_AND, NULL)));
	else if (*line == '|' && *(line + 1) == '|')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(LOGICAL_OR, NULL)));
	else if (*line == '<' && *(line + 1) == '<')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(HEREDOCS, NULL)));
	else if (*line == '>' && *(line + 1) == '>')
		ft_lstadd_back(tokens, ft_lstnew(tok_new(DRC, NULL)));
	else
		return (0);
	(*line_ptr) += 2;
	return (1);
}

/* Handles '' and "" and regular strings */
static int	lexer_handle_strings(t_minishell *mnsh,
								t_list **tokens, const char **line_ptr)
{
	const char	*line;
	char		*cut_str;
	int			len;

	line = *line_ptr;
	cut_str = NULL;
	if (*line == ' ')
		return (0);
	len = lexer_get_string_len(line);
	if (len == -1)
		return (1);
	if (*line == '*' || *line == '$')
	{
		ft_lstadd_back(tokens, ft_lstnew(
				tok_new(NEED_SPLIT, lexer_cut_string(mnsh, line, len))));
	}
	else
	{
		ft_lstadd_back(tokens, ft_lstnew(
				tok_new(ESCAPED_STRING, lexer_cut_string(mnsh, line, len))));
	}
	*line_ptr += len;
	return (0);
}

static void	lexer_split_splittable_tokens(t_list **tokens)
{
	t_list	*l[2];
	char	**s;
	int		i;

	l[0] = *tokens;
	while (l[0])
	{
		if (((t_token *)(l[0]->content))->type == NEED_SPLIT
			&& !space_only_string(((t_token *)(l[0]->content))->data))
		{
			i = -1;
			l[1] = NULL;
			s = ft_split(((t_token *)(l[0]->content))->data, ' ');
			while (s[++i])
				ft_lstadd_back(&l[1], ft_lstnew(tok_new(ESCAPED_STRING, s[i])));
			ft_lstlast(l[1])->next = l[0]->next;
			free(((t_token *)(l[0]->content))->data);
			ft_memcpy(l[0], l[1], sizeof(t_list));
			free_mult(2, (void *[2]){l[1], s});
		}
		else if (((t_token *)(l[0]->content))->type == NEED_SPLIT)
			l[0] = ft_lstdelone_ptr(tokens, l[0], (void (*)(void *))token_free);
		else
			l[0] = l[0]->next;
	}
}

t_list	*lexer(t_minishell *mnsh, const char *line)
{
	t_list	*tokens;

	tokens = NULL;
	while (*line)
	{
		if (*line != ' ')
		{
			if (lexer_handle_special_char(&tokens, &line))
				continue ;
			else if (lexer_handle_special_chars(&tokens, &line))
				continue ;
			if (lexer_handle_strings(mnsh, &tokens, &line))
			{
				ft_lstclear(&tokens, (void (*)(void *))token_free);
				mnsh_throw_error(LEXER_ERROR,
					"Expected \' or \", found nothing.\n");
				return (NULL);
			}
		}
		else
			line++;
	}
	lexer_split_splittable_tokens(&tokens);
	return (tokens);
}
