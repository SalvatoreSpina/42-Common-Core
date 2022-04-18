/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:35:22 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:37 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate_a(t_mem *mem)
{
	push_top_to_bot(&(mem->a));
	if (mem->print)
		ft_putstr("ra");
}
