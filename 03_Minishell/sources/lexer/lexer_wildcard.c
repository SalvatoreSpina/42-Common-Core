/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:40:52 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:17:49 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "dirent.h"

static bool	isc(const char *src)
{
	return (*src == '(' || *src == ')' || *src == '|'
		|| (*src == '&' && *(src + 1) == '&') || *src == '<'
		|| *src == '>' || *src == ' ');
}

bool	lexer_is_wildcard(const char *src, int src_idx)
{
	return (src[src_idx] == '*'
		&& (src_idx == 0 || isc(&src[src_idx - 1]))
		&& (src[(src_idx) + 1] == '\0' || isc(&src[src_idx + 1])));
}

int	lexer_escape_wildcard(t_minishell *mnsh, char *dst, char *src, int *idx)
{
	char			cwd[4096];
	DIR				*wd;
	struct dirent	*cur_file;
	bool			first;

	(void) mnsh;
	(void) src;
	getcwd(cwd, 4096);
	wd = opendir(cwd);
	cur_file = readdir(wd);
	first = true;
	while (cur_file != NULL)
	{
		if (ft_strcmp(".", cur_file->d_name) != 0
			&& ft_strcmp("..", cur_file->d_name) != 0)
		{
			if (!first)
				ft_strcat(dst, " ");
			ft_strcat(dst, cur_file->d_name);
			first = false;
		}
		cur_file = readdir(wd);
	}
	(*idx)++;
	return (1);
}

int	lexer_get_wildcard_length(t_minishell *mnsh, int *idx)
{
	int				len;
	char			cwd[4096];
	DIR				*wd;
	struct dirent	*curf;
	bool			first;

	(void) mnsh;
	len = 0;
	getcwd(cwd, 4096);
	wd = opendir(cwd);
	curf = readdir(wd);
	first = true;
	while (curf != NULL)
	{
		if (ft_strcmp(".", curf->d_name) && ft_strcmp("..", curf->d_name))
		{
			if (!first)
				len += 1;
			len += ft_strlen(curf->d_name);
			first = false;
		}
		curf = readdir(wd);
	}
	(*idx)++;
	return (len);
}
