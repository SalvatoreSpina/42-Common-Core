/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:10:57 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 18:48:59 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

typedef enum e_status
{
	REGULAR = 0,
	IN_DOUBLE_QUOTE = 1,
	IN_SINGLE_QUOTE = 2,
}	t_status;

static void	lexer_update_status_accordingly(t_status *st, const char c)
{
	if (c == '\"' && (*st & IN_DOUBLE_QUOTE) == IN_DOUBLE_QUOTE)
		*st &= ~IN_DOUBLE_QUOTE;
	else if (c == '\'' && (*st & IN_SINGLE_QUOTE) == IN_SINGLE_QUOTE)
		*st &= ~IN_SINGLE_QUOTE;
	else if (c == '\"' && (*st & IN_DOUBLE_QUOTE) != IN_DOUBLE_QUOTE
		&& *st == REGULAR)
		*st |= IN_DOUBLE_QUOTE;
	else if (c == '\'' && (*st & IN_SINGLE_QUOTE) != IN_SINGLE_QUOTE
		&& *st == REGULAR)
		*st |= IN_SINGLE_QUOTE;
}

/* Should be good but might need extra debugging */
/* Might need debugging with the condition in the while and the rewrite*/
int	lexer_get_string_len(const char *line)
{
	t_status	status;
	int			i;

	status = REGULAR;
	i = 0;
	while (!(status == REGULAR
			&& (line[i] == '\0' || line[i] == ' '
				|| (line[i] == '&' && line[i + 1] == '&')
				|| line[i] == '|' || line[i] == '(' || line[i] == ')'
				|| line[i] == '<' || line[i] == '>')))
	{
		if (line[i] == '\"' || line[i] == '\'')
			lexer_update_status_accordingly(&status, line[i]);
		else if (line[i] == '\0' && status != REGULAR)
			return (-1);
		i++;
	}
	return (i);
}

typedef struct s_lexer_esc_len
{
	int		sz;
	int		i;
	char	tok;	
}	t_lexer_esc_len;

int	lexer_get_esc_strlen(t_minishell *mnsh, const char *line, int len)
{
	t_lexer_esc_len	s;

	s.sz = 0;
	s.i = 0;
	while (s.i < len)
	{
		if (line[s.i] != '\"' && line[s.i] != '\'' && !lexer_is_env(&line[s.i])
			&& !lexer_is_wildcard(line, s.i))
			s.sz += !!(++s.i);
		else if (line[s.i] == '\"' || line[s.i] == '\'')
		{
			s.tok = line[s.i++];
			while (line[s.i] != s.tok)
			{
				if (lexer_is_env(&line[s.i]) && s.tok != '\'')
					s.sz += lexer_get_env_length(mnsh, line, &(s.i));
				else
					s.sz += !!(++s.i);
			}
			s.i++;
		}
		else
			s.sz += lexer_get_special_seq_len(mnsh, (char *) line, &(s.i));
	}
	return (s.sz);
}

int	lexer_escape_str(t_minishell *mnsh, char *dst, char *src, int *src_idx)
{
	int		dst_len;
	char	tok;

	dst_len = 0;
	if (lexer_is_env(&src[*src_idx]))
		dst_len += lexer_escape_env(mnsh, dst, src, src_idx);
	else if (lexer_is_wildcard(src, *src_idx))
		dst_len += lexer_escape_wildcard(mnsh, dst, src, src_idx);
	else if (src[*src_idx] == '\"' || src[*src_idx] == '\'')
	{
		tok = src[(*src_idx)++];
		while (src[*src_idx] != tok)
		{
			if (lexer_is_env(&src[*src_idx]) && tok != '\'')
				dst_len += lexer_escape_env(mnsh, dst, src, src_idx);
			else
				dst[dst_len++] = src[(*src_idx)++];
		}
		(*src_idx)++;
	}
	else
		dst[dst_len++] = src[(*src_idx)++];
	return (dst_len);
}

/* Cuts the string and performs escaping on it, since to arrive here
	the input has to be valid, it makes writing this code easier. */
/* ToDO: ESCAPE WHEN IN REGULAR STATE TOO */
char	*lexer_cut_string(t_minishell *mnsh, const char *line, int len)
{
	char		*esc;
	int			esc_len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	esc_len = lexer_get_esc_strlen(mnsh, line, len);
	esc = ft_calloc(esc_len + 1, sizeof(char));
	while (i < len)
	{
		if (line[i] != '\"' && line[i] != '$'
			&& line[i] != '\'' && line[i] != '*')
		{
			esc[j++] = line[i++];
		}
		else
		{
			j += lexer_escape_str(mnsh, &esc[j], (char *) line, &i);
		}
	}
	return (esc);
}
