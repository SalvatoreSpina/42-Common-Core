/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:53:39 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:00:45 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "libft.h"
#include "minishell.h"

#include <stdio.h>

static int	mnsh_find_environ_by_name(void *environ, void *str)
{
	return (ft_strcmp(((t_environ *) environ)->name, str));
}

t_environ	*mnsh_get_in_environ(t_minishell *mnsh, char *var_name)
{
	t_list	*node;

	node = ft_lstfind(mnsh->environ, &mnsh_find_environ_by_name,
			(void *) var_name);
	if (node)
		return (node->content);
	else
		return (NULL);
}

void	mnsh_set_in_environ(t_minishell *mnsh, char *var_name,
		char *value, bool ed)
{
	t_environ	*env;

	env = mnsh_get_in_environ(mnsh, var_name);
	if (env)
	{
		env->value = value;
		env->should_display_in_env = true;
	}
	else
	{
		ft_lstadd_back(&mnsh->environ, ft_lstnew(mnsh_environ_create(var_name,
					value, ed)));
	}
}

void	mnsh_unset_in_environ(t_minishell *mnsh, char *var_name)
{
	t_list	*to_unset;
	t_list	*prev;
	t_list	*current;

	to_unset = ft_lstfind(mnsh->environ, &mnsh_find_environ_by_name, var_name);
	if (to_unset)
	{
		prev = mnsh->environ;
		current = mnsh->environ;
		while (current)
		{
			if (current && current->next == to_unset)
			{
				prev = current;
				break ;
			}
			if (current)
				current = current->next;
		}
		prev->next = to_unset->next;
		ft_lstdelone(to_unset, &mnsh_environ_delete);
	}
}

char	**environ_build_envp(t_minishell *mnsh)
{
	char		**ret;
	t_list		*head;
	int			i;
	char		*tmp;

	ret = ft_calloc(ft_lstsize(mnsh->environ) + 1, sizeof(char *));
	i = 0;
	head = mnsh->environ;
	while (head)
	{
		tmp = ft_strjoin(((t_environ *) head->content)->name, "=");
		ret[i] = ft_strjoin(tmp, ((t_environ *) head->content)->value);
		free(tmp);
		head = head->next;
		i++;
	}
	return (ret);
}
