/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:25:12 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 18:57:41 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"

int	mnsh_builtin_unset(t_minishell *mnsh, char **argv)
{
	argv++;
	while (*argv)
		mnsh_unset_in_environ(mnsh, *argv++);
	return (0);
}
