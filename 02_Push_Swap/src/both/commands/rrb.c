/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:35:58 by sspina            #+#    #+#             */
/*   Updated: 2022/01/03 17:35:59 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rev_rotate_b(t_mem *mem)
{
	push_bot_to_top(&(mem->b));
	if (mem->print)
		ft_putstr("rrb");
}
