/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:52 by sspina            #+#    #+#             */
/*   Updated: 2022/01/03 17:42:50 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	rotate(t_mem *mem, int rot_a, int rot_b)
{
	rotate_both(mem, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		rotate_a(mem);
	}
	while (rot_a < 0)
	{
		rot_a++;
		rev_rotate_a(mem);
	}
	while (rot_b > 0)
	{
		rot_b--;
		rotate_b(mem);
	}
	while (rot_b < 0)
	{
		rot_b++;
		rev_rotate_b(mem);
	}
}

void	rotate_both(t_mem *mem, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_a)--;
		(*rot_b)--;
		rotate_a_b(mem);
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		(*rot_a)++;
		(*rot_b)++;
		rev_rotate_a_b(mem);
	}
}
