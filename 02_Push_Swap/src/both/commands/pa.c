/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:35:07 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:47 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	push_a(t_mem *mem)
{
	push_top(&(mem->b), &(mem->a));
	if (mem->print)
		ft_putstr("pa");
}
