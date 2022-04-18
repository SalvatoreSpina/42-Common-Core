/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:55:24 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:24:23 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_execution_state
{
	int	last_ret;
	int	stdin_fd;
}	t_execution;

typedef struct s_process_ctx
{
	int	pid;
	int	in_rd;
	int	out_rd;
}	t_process_ctx;

/* Me and the homies disregard linked lists */
typedef struct s_minishell
{
	t_list		*environ;
	t_execution	exec;
	t_list		*running_processes;
	int			save_stdout;
	int			save_stdin;
}	t_minishell;

typedef enum e_error
{
	LEXER_ERROR,
	PARSER_ERROR,
	EXECUTION_ERROR,
	FILE_ERROR
}	t_error;

extern t_minishell	*g_mnsh;
t_minishell			*g_mnsh;

void	mnsh_throw_error(t_error err, const char *str);
char	*mnsh_get_prompt(t_minishell *mnsh);
void	handle_line(t_minishell *mnsh, char *line);
void	free_2d(void **a);
void	free_mult(int count, void **addrs);
void	close_mult(int n, int *fds);
void	enable_signals(void);
bool	checker_is_valid(t_list *toks);
char	*folder_or_perm(char *path);
char	*no_file_or_bin(char *path);
bool	space_only_string(char *str);

#endif
