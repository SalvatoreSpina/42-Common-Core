/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:45 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:35 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipe_write(char *limiter, int fd[2])
{
	size_t	limiter_length;
	char	*line;

	limiter_length = ft_strlen(limiter);
	while (1)
	{
		ft_printf("pipex here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			close_util(fd);
			exit(EXIT_FAILURE);
		}
		if (line[limiter_length] == '\n' && limiter && \
			!ft_strncmp(line, limiter, limiter_length))
		{
			close_util(fd);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free_point(&line);
	}
}

static void	here_doc(int argc, char *argv[])
{
	pid_t	pid;
	int		fd[2];

	if (argc != 6)
		exit(error_argc());
	if (pipe(fd) == -1)
		exit(error_general("pipe"));
	pid = fork();
	if (pid == -1)
		error_general("fork");
	if (pid == 0)
		pipe_write(argv[2], fd);
	else
	{
		dup2_ok(fd[0], STDIN_FILENO);
		close_util(fd);
		waitpid(pid, NULL, 0);
	}
}

static int	open_file(char *file, t_open flag)
{
	int	fd;

	fd = 0;
	if (flag == APPEND)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC);
	if (flag == TRUNC)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC);
	if (flag == RDONLY)
		fd = open(file, O_RDONLY | O_CLOEXEC);
	if (fd == -1)
		error_nofile(file);
	return (fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_files	files;
	int		i_cmd;

	if (!(argc >= 5))
		return (error_argc());
	if (argv[1] && !ft_strncmp(argv[1], "here_doc", 8) && argv[1][8] == '\0')
	{
		i_cmd = 3;
		here_doc(argc, argv);
		files.output = open_file(argv[argc - 1], APPEND);
	}
	else
	{
		i_cmd = 2;
		files.input = open_file(argv[1], RDONLY);
		if (files.input > 0)
			dup2_ok(files.input, STDIN_FILENO);
		files.output = open_file(argv[argc - 1], TRUNC);
	}
	while (i_cmd < argc - 2)
		child_cmd(argv[i_cmd++], envp, files);
	if (files.output == -1)
		exit(EXIT_FAILURE);
	dup2_ok(files.output, STDOUT_FILENO);
	exec_cmd(argv[argc - 2], envp);
}
