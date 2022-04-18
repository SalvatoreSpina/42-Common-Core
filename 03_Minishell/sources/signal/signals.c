/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:45:00 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:00:12 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

static void	handle_sigint(int sig)
{
	t_list		*curr;
	int			advanced;

	(void) sig;
	advanced = 0;
	curr = g_mnsh->running_processes;
	while (curr)
	{
		kill(((t_process_ctx *)(curr->content))->pid, SIGINT);
		curr = curr->next;
		advanced = 1;
	}
	if (!advanced)
		g_mnsh->exec.last_ret = 1;
	write(1, "\n", 1);
	if (rl_done)
		return ;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	handle_sigquit(int sig)
{
	(void) sig;
	rl_on_new_line();
	rl_redisplay();
}

void	enable_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
