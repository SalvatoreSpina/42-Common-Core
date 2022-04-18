/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:59:00 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 18:06:31 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

bool	space_only_string(char *str)
{
	if (!ft_strlen(str))
		return (true);
	while (*str)
		if (*str++ != ' ')
			return (false);
	return (true);
}

char	*no_file_or_bin(char *path)
{
	if (ft_strchr(path, '/'))
		return ("no such file or directory");
	else
		return ("command not found");
}

char	*folder_or_perm(char *path)
{
	DIR	*d;

	d = opendir(path);
	if (d != NULL)
	{
		closedir(d);
		return ("is a directory");
	}
	return ("permission denied");
}

void	mnsh_throw_error(t_error err, const char *str)
{
	if (err == LEXER_ERROR)
		ft_putstr_fd("mnsh: lexer error: ", 2);
	if (err == PARSER_ERROR)
		ft_putstr_fd("mnsh: parser error: ", 2);
	if (err == EXECUTION_ERROR)
		ft_putstr_fd("mnsh: execution error: ", 2);
	ft_putstr_fd((char *) str, 2);
}
