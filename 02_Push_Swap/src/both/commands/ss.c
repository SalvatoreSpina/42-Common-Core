/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:36:42 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:51 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap_a_b(t_mem *mem)
{
	swap(&(mem->b));
	swap(&(mem->a));
	if (mem->print)
		ft_putstr("ss");
}
