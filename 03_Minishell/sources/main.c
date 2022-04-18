/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:18:48 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:00:02 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "environ.h"
#include "escaper.h"
#include "exec.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h>

extern char	**environ;

static void	mnsh_init(t_minishell *blockchienne)
{
	mnsh_environ_init(blockchienne, environ);
	blockchienne->running_processes = NULL;
	blockchienne->exec.last_ret = 0;
	blockchienne->exec.stdin_fd = -1;
}

static void	show_cc(bool enabled)
{
	struct termios	t;

	tcgetattr(0, &t);
	if (enabled)
		t.c_lflag |= ECHOCTL;
	else
		t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

int	main(void)
{
	t_minishell	mnsh;
	char		*line;

	enable_signals();
	mnsh_init(&mnsh);
	g_mnsh = &mnsh;
	mnsh.save_stdout = dup(STDOUT_FILENO);
	mnsh.save_stdin = dup(STDIN_FILENO);
	while ("bleroy: sexy, beau, magnifique")
	{
		show_cc(false);
		line = readline(mnsh_get_prompt(&mnsh));
		if (!line)
			break ;
		if (line[0] != '\0')
			add_history(line);
		show_cc(true);
		handle_line(&mnsh, line);
		free(line);
	}
	write(1, "exit\n", 5);
	close(mnsh.save_stdout);
	close(mnsh.save_stdin);
	return (0);
}
