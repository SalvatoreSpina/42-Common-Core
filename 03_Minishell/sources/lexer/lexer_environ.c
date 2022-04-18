/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:09:25 by achansel          #+#    #+#             */
/*   Updated: 2022/02/16 21:54:05 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "minishell.h"
#include <libft.h>
#include <stdio.h>

static int	lexer_number_len(int no)
{
	int	i;

	i = no <= 0;
	while (no != 0)
	{
		no /= 10;
		i++;
	}
	return (i);
}

static char	*lexer_extract_env_name(const char *src, int *idx)
{
	int		name_len;
	char	c;
	char	*ret;

	name_len = 0;
	c = src[++(*idx) + name_len];
	while (c != '$' && c != ' ' && c != '\0' && c != '<' && c != '>' && c != '&'
		&& c != '|' && c != '\'' && c != '\"')
		c = src[*idx + ++name_len];
	ret = ft_strndup((char *) &src[*idx], name_len);
	*idx += name_len;
	return (ret);
}

int	lexer_is_env(const char *str)
{
	return (*str == '$' && *(str + 1) != ' ' && *(str + 1) != '\0'
		&& *(str + 1) != '<' && *(str + 1) != '>' && *(str + 1) != '&'
		&& *(str + 1) != '|' && *(str + 1) != '$' && *(str + 1) != '\"'
		&& *(str + 1) != '\'');
}

int	lexer_get_env_length(t_minishell *mnsh, const char *src, int *idx)
{
	char		*name;
	size_t		length;
	t_environ	*env;

	name = lexer_extract_env_name(src, idx);
	if (ft_strcmp(name, "?") == 0)
		return (lexer_number_len(mnsh->exec.last_ret));
	env = mnsh_get_in_environ(mnsh, name);
	if (env)
		length = ft_strlen(env->value);
	else
		length = 0;
	free(name);
	return (length);
}

int	lexer_escape_env(t_minishell *mnsh, char *dst, char *src, int *idx)
{
	char		*name;
	t_environ	*env;
	char		*val;
	int			len;

	name = lexer_extract_env_name(src, idx);
	if (ft_strcmp(name, "?") == 0)
	{
		val = ft_itoa(mnsh->exec.last_ret);
		len = lexer_number_len(mnsh->exec.last_ret);
		ft_strcat(dst, val);
		free(val);
	}
	env = mnsh_get_in_environ(mnsh, name);
	if (env)
	{
		val = env->value;
		len = ft_strlen(val);
		ft_strcat(dst, val);
	}
	else
		len = 0;
	free(name);
	return (len);
}
