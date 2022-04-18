/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:43:38 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:15:48 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

t_token	*tok_new(t_token_type type, const char *data)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	tok->data = (char *) data;
	tok->type = type;
	return (tok);
}

void	token_free(t_token	*tok)
{
	if (tok->data)
		free((void *) tok->data);
	free(tok);
}
