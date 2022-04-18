/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:16:35 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 19:01:08 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"

int	mnsh_builtin_env(t_minishell	*mnsh, char **argv)
{
	t_list	*current;

	(void) argv;
	current = mnsh->environ;
	while (current)
	{
		if (((t_environ *) current->content)->should_display_in_env)
			printf("%s=%s\n", ((t_environ *) current->content)->name,
				((t_environ *) current->content)->value);
		current = current->next;
	}
	return (0);
}
