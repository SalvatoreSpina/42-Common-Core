/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:35:27 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:05 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate_b(t_mem *mem)
{
	push_top_to_bot(&(mem->b));
	if (mem->print)
		ft_putstr("rb");
}
