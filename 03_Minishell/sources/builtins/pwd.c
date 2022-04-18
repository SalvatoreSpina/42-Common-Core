/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:09:10 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 18:57:13 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mnsh_builtin_pwd(t_minishell	*mnsh, char **argv)
{
	char	cwd[4096];

	(void) mnsh;
	(void) argv;
	getcwd(cwd, 4096);
	printf("%s\n", cwd);
	return (0);
}
