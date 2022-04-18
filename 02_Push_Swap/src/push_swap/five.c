/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:37 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:45 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	five_optimized(t_mem *mem)
{
	t_list	*l;
	int		minimum;
	int		current;

	while (tagged(mem->a, 0) || tagged(mem->a, mem->max - 1))
	{
		l = mem->a;
		minimum = INT_MAX;
		while (l)
		{
			if (l->index == 0 || l->index == mem->max - 1)
			{
				current = distance_to_top(mem->a, l->index);
				if (ft_abs(current) < ft_abs(minimum))
					minimum = current;
			}
			l = l->next;
		}
		if (minimum == 0)
			push_b(mem);
		if (minimum < 0)
			rev_rotate_a(mem);
		if (minimum > 0)
			rotate_a(mem);
	}
}

int	tagged(t_list *list, int tag)
{
	while (list)
	{
		if (list->index == tag)
			return (1);
		list = list->next;
	}
	return (0);
}
