/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:56 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:33 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	resolve(t_mem *m, int cur_group)
{
	int	distance;

	initialise_values(m);
	while (m->size >= m->big && cur_group <= (m->group_number + 1))
	{
		m->temp = closest_in_group(m->a, cur_group, m->group_size);
		if (m->temp == NULL && ++cur_group)
			continue ;
		distance = distance_to_top(m->a, m->temp->index);
		if (m->a && swap_good(m->a))
		{
			swap_a(m);
			m->big = find_biggest_asc_order(m->a, 1);
		}
		else if (m->a && !m->a->keep && distance == 0)
		{
			push_b(m);
			(m->size)--;
		}
		else if (m->group_number == 1)
			rotate_a_b(m);
		else
			rotate(m, ft_min(1, ft_max(-1, distance)), 0);
	}
	fill_b(m);
}

void	fill_b(t_mem *m)
{
	int	rot_a;
	int	rot_b;

	while (m->b)
	{
		calculate_b_rotation(m, INT_MAX, &rot_a, &rot_b);
		rotate(m, rot_a, rot_b);
		push_a(m);
		(m->size)++;
	}
	rotate(m, distance_to_top(m->a, 0), 0);
}

int	insert_distance(t_list *list, int t, int size)
{
	t_list	*p;
	t_list	*c;
	int		c_max[2];
	int		i;

	i = 0;
	p = get_last(list);
	c = list;
	c_max[1] = INT_MAX;
	while (c)
	{
		if ((p->index > c->index && (t < c->index || t > p->index))
			|| (t > p->index && t < c->index))
		{
			c_max[0] = i;
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_abs(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (c_max[1]);
}

void	calculate_b_rotation(t_mem *m, int max_dist, int *rot_a, int *rot_b)
{
	int	dist_total;
	int	insert;
	int	distance_b;
	int	i;

	i = 0;
	m->temp = m->b;
	while (m->temp)
	{
		distance_b = distance_to_tag(i++, m->max - m->size);
		insert = insert_distance(m->a, m->temp->index, m->size);
		dist_total = ft_abs(insert) + ft_abs(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total -= ft_min(distance_b, insert);
		if (insert < 0 && distance_b < 0)
			dist_total += ft_max(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*rot_a = insert;
			*rot_b = distance_b;
		}
		m->temp = m->temp->next;
	}
}

int	swap_good(t_list *list)
{
	t_list	fake;
	t_list	fake2;
	int		count;
	int		count2;

	fake.next = &fake2;
	fake.index = list->next->index;
	fake2.next = list->next->next;
	fake2.index = list->index;
	count = find_biggest_asc_order(list, 0);
	count2 = find_biggest_asc_order(&fake, 0);
	if (count2 > count)
		return (1);
	return (0);
}
