/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:08:47 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 18:48:08 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

t_list	*lexer(t_minishell *mnsh, const char *line);
int		lexer_is_env(const char *str);
int		lexer_get_env_length(t_minishell *mnsh, const char *src, int *idx);
int		lexer_escape_env(t_minishell *mnsh, char *dst, char *src, int *idx);
int		lexer_get_string_len(const char *line);
int		lexer_get_esc_strlen(t_minishell *mnsh, const char *line, int len);
int		lexer_escape_str(t_minishell *mnsh, char *dst, char *src, int *src_idx);
char	*lexer_cut_string(t_minishell *mnsh, const char *line, int len);
bool	lexer_is_wildcard(const char *src, int src_idx);
int		lexer_escape_wildcard(t_minishell *msh, char *dst, char *src, int *idx);
int		lexer_get_wildcard_length(t_minishell *mnsh, int *idx);

static inline int	lexer_get_special_seq_len(t_minishell *m, char *l, int *i)
{
	if (lexer_is_env(&l[*i]))
		return (lexer_get_env_length(m, l, i));
	else if (lexer_is_wildcard(l, *i))
		return (lexer_get_wildcard_length(m, i));
	else
		return (0);
}

#endif