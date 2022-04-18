/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:38 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:04 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_error	error_argc(void)
{
	ft_putendl_fd("Error: invalid number of arguments", STDERR_FILENO);
	ft_putendl_fd("Hint: ./pipex <file1> <cmd1> <cmd2> ... <cmdn> <file2>",
		STDERR_FILENO);
	ft_putendl_fd("Hint: ./pipex here_doc LIMITER <cmd1> <cmd2> <file>",
		STDERR_FILENO);
	return (ERRSTAT_GENERAL);
}

t_error	error_nofile(char *file)
{
	ft_putstr_fd("Error: no such file or directory:", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
	return (ERRSTAT_GENERAL);
}

t_error	error_notcmd(char *cmd)
{
	ft_putstr_fd("Error: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
	return (ERRSTAT_NOTCMD);
}

t_error	error_noperm(char *name)
{
	ft_putstr_fd("Error: permission denied: ", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
	return (ERRSTAT_NOPERM);
}

t_error	error_general(char *name)
{
	perror(name);
	return (ERRSTAT_GENERAL);
}
