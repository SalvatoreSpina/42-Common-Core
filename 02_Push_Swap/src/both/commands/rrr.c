/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:36:13 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:36 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rev_rotate_a_b(t_mem *mem)
{
	push_bot_to_top(&(mem->b));
	push_bot_to_top(&(mem->a));
	if (mem->print)
		ft_putstr("rrr");
}
