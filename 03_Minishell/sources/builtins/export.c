/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:25:12 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:01:22 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

static void	print_export(t_minishell *mnsh)
{
	t_list	*current;
	char	*str;

	current = mnsh->environ;
	while (current)
	{
		write(1, "declare -x ", 11);
		write(1, ((t_environ *) current->content)->name,
			ft_strlen(((t_environ *) current->content)->name));
		if (((t_environ *) current->content)->value)
		{
			write(1, "=\"", 2);
			str = ((t_environ *) current->content)->value;
			while (*str)
			{
				if (*str == '\"' || *str == '$')
					write(1, "\\", 1);
				write(1, str++, 1);
			}
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		current = current->next;
	}
}

int	mnsh_builtin_export(t_minishell *mnsh, char **argv)
{
	char	*name;
	char	*val;
	int		i;

	i = 1;
	while (argv[i])
	{
		val = ft_strchr(argv[i], '=');
		if (val && val != argv[i] && !ft_strchr(val + 1, '='))
		{
			name = ft_strndup(argv[i], val - argv[i]);
			val++;
			mnsh_set_in_environ(mnsh, name, ft_strdup(val), true);
		}
		if (!val)
			mnsh_set_in_environ(mnsh, ft_strdup(argv[i]), NULL, false);
		i++;
	}
	if (i == 1)
		print_export(mnsh);
	return (0);
}
