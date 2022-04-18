/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:10:56 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:19:12 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include <fcntl.h>
#include <unistd.h>

bool	is_path(char *str)
{
	return (!!ft_strchr(str, '/') && access(str, F_OK) == 0);
}

bool	find_in_path(t_minishell *mnsh, char *binary_name, char *dst)
{
	t_environ	*path;
	char		**dirs;
	char		*right_path;
	int			fd;
	char		*tmp;

	path = mnsh_get_in_environ(mnsh, "PATH");
	if (!path || !ft_strlen(binary_name))
		return (false);
	dirs = ft_split(path->value, ':');
	while (*dirs)
	{
		tmp = ft_strjoin(*dirs, "/");
		right_path = ft_strjoin(tmp, binary_name);
		free(tmp);
		fd = open(right_path, O_RDONLY);
		if (fd != -1)
		{
			ft_strcpy(dst, right_path);
			close(fd);
		}
		dirs++;
	}
	return (dst[0] != '\0');
}
