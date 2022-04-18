/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:44:44 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:15:48 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_type
{
	LPAR = 10,
	RPAR = 11,
	ESCAPED_STRING = 12,
	NEED_SPLIT = 18,
	PIPE = 13,
	LC = 1,
	HEREDOCS = 2,
	RC = 4,
	DRC = 8,
	LOGICAL_AND = 14,
	LOGICAL_OR = 15,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*data;
}	t_token;

t_token	*tok_new(t_token_type type, const char *data);
void	token_free(t_token	*tok);

#endif