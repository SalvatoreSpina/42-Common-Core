/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:21:37 by sspina            #+#    #+#             */
/*   Updated: 2022/04/09 19:00:26 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"
#include "escaper.h"

#include <stdio.h>

char	*mnsh_get_prompt(t_minishell *mnsh)
{
	t_environ	*ps1;

	ps1 = mnsh_get_in_environ(mnsh, "PS1");
	if (ps1)
		return (ps1->value);
	return ("$> ");
}
