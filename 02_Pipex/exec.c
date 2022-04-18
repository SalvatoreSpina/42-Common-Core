/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:20 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:30 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_paths(char **paths)
{
	size_t	i;

	i = 0;
	while (paths[i])
	{
		free_point(&paths[i]);
		i++;
	}
	free_ppoint(&paths);
}

static char	*find_command(char *cmd, char **paths)
{
	char	*path;
	char	*tmp;
	size_t	i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free_point(&tmp);
		if (access(path, F_OK) == 0)
		{
			free_paths(paths);
			return (path);
		}
		else
			free_point(&path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

static char	*parse_path(char *cmd, char *envp[])
{
	char	**paths;
	size_t	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		exit(error_general("ft_split"));
	return (find_command(cmd, paths));
}

void	exec_cmd(char *argv, char *envp[])
{
	char	**cmd;

	if (!*argv)
		exit(error_noperm(""));
	cmd = ft_split(argv, ' ');
	if (!cmd)
		exit(error_general("ft_split"));
	if (cmd[0] && ft_strchr(cmd[0], '/'))
		if (execve(cmd[0], &cmd[0], envp) == -1)
			exit(error_notcmd(cmd[0]));
	if (execve(parse_path(cmd[0], envp), cmd, envp) == -1)
		exit(error_notcmd(cmd[0]));
}

void	child_cmd(char *argv, char *envp[], t_files files)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_general("pipe");
	pid = fork();
	if (pid == -1)
		error_general("fork");
	if (pid == 0)
	{
		if (files.input == -1)
		{
			close_util(fd);
			exit(EXIT_FAILURE);
		}
		dup2_ok(fd[1], STDOUT_FILENO);
		close_util(fd);
		exec_cmd(argv, envp);
	}
	dup2_ok(fd[0], STDIN_FILENO);
	close_util(fd);
	waitpid(-1, NULL, WNOHANG);
}
