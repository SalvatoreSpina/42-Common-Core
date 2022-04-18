/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_context.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:02:35 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 20:19:00 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process_ctx	*make_pctx(int pid, int fdin, int fdout)
{
	t_process_ctx	*ctx;

	ctx = (t_process_ctx *) malloc(sizeof(t_process_ctx));
	ctx->pid = pid;
	ctx->in_rd = fdin;
	ctx->out_rd = fdout;
	return (ctx);
}
