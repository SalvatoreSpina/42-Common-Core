/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:39:01 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:33 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	initialise_values(t_mem *mem)
{
	mem->big = find_biggest_asc_order(mem->a, 1);
	mem->size = list_size(mem->a);
	mem->group_number = ft_max(1, (int)(mem->max / 150.0));
	mem->group_size = mem->max / mem->group_number;
}

t_list	*closest_in_group(t_list *list, int cur_group, int group_size)
{
	t_list	*closest;
	t_list	*current;
	int		distance;
	int		cur_dist;

	distance = INT_MAX;
	closest = NULL;
	current = list;
	while (current)
	{
		if (current->index <= group_size * cur_group && !current->keep)
		{
			cur_dist = distance_to_top(list, current->index);
			if (ft_abs(cur_dist) < ft_abs(distance))
			{
				distance = cur_dist;
				closest = current;
				if (distance == 0)
					break ;
			}
		}
		current = current->next;
	}
	return (closest);
}

int	distance_to_top(t_list *a, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = list_size(a);
	while (a)
	{
		if (a->index == tag)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}

int	distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}
