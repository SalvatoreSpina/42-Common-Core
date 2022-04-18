/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:44 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:45 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	find_biggest_asc_order(t_list *start, int set)
{
	t_list	*t;
	int		max;
	int		count;
	t_list	*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = index_asc_order(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (set)
		index_asc_order(start, max_keep, 1);
	return (max);
}

int	index_asc_order(t_list *list, t_list *start, int set)
{
	t_list	*asc_ord;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	asc_ord = start;
	while (asc_ord)
	{
		if (set)
			asc_ord->keep = 0;
		if (asc_ord->index > max_tag)
		{
			max_tag = asc_ord->index;
			count++;
			if (set)
				asc_ord->keep = 1;
		}
		asc_ord = asc_ord->next;
		if (asc_ord == NULL)
			asc_ord = list;
		if (asc_ord == start)
			break ;
	}
	return (count);
}
