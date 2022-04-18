/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:49 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:30 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERRMSG_ARGC "Error: invalid number of arguments"
# define ERRMSG_USAGE1 "(hint) ./pipex <file1> <cmd1> <cmd2> ... <cmdn> <file2>"
# define ERRMSG_USAGE2 "(hint): ./pipex here_doc LIMITER <cmd1> <cmd2> <file>"
# define ERRMSG_NOTCMD "Error: command not found: "
# define ERRMSG_NOFILE "Error: no such file or directory: "
# define ERRMSG_NOPERM "Error: permission denied: "

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef enum e_error
{
	ERRSTAT_GENERAL = 1,
	ERRSTAT_NOPERM = 126,
	ERRSTAT_NOTCMD = 127,
}	t_error;

typedef enum e_open
{
	APPEND,
	TRUNC,
	RDONLY,
}	t_open;

typedef struct s_files
{
	int	input;
	int	output;
}	t_files;

void	exec_cmd(char *argv, char *envp[]);
void	child_cmd(char *argv, char *envp[], t_files files);

t_error	error_argc(void);
t_error	error_nofile(char *file);
t_error	error_notcmd(char *cmd);
t_error	error_noperm(char *name);
t_error	error_general(char *name);

void	close_util(int fd[2]);
void	dup2_ok(int fd1, int fd2);
void	free_point(char **ptr);
void	free_ppoint(char ***ptr);

#endif
