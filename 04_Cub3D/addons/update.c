/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:01:00 by achansel          #+#    #+#             */
/*   Updated: 2022/07/06 12:17:44 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>
#include <stdlib.h>

/*
	Just loops the frames of the animation
*/
static void	update_animations(t_everything *all, unsigned long now)
{
	int			i;
	t_animable	*curr;

	i = 0;
	while (i < all->animables_len)
	{
		curr = all->animables[i++];
		if (curr->frame_count && curr->last_update
			+ curr->frame_time < now * 1000 / CLOCKS_PER_SEC)
		{
			curr->frame_pointer = (curr->frame_pointer + 1) % curr->frame_count;
			curr->last_update = now * 1000 / CLOCKS_PER_SEC;
			all->redraw = true;
		}
	}
}

int	switch_door(t_everything *all)
{
	int	x;
	int	y;

	x = all->ray.our_x;
	y = all->ray.our_y;
	if (all->info.map[x + 1][y] == 'C')
		all->info.map[x + 1][y] = 'A';
	else if (all->info.map[x + 1][y] == 'A')
		all->info.map[x + 1][y] = 'C';
	if (all->info.map[x - 1][y] == 'C')
		all->info.map[x - 1][y] = 'A';
	else if (all->info.map[x - 1][y] == 'A')
		all->info.map[x - 1][y] = 'C';
	if (all->info.map[x][y + 1] == 'C')
		all->info.map[x][y + 1] = 'A';
	else if (all->info.map[x][y + 1] == 'A')
		all->info.map[x][y + 1] = 'C';
	if (all->info.map[x][y - 1] == 'C')
		all->info.map[x][y - 1] = 'A';
	else if (all->info.map[x][y - 1] == 'A')
		all->info.map[x][y - 1] = 'C';
	return (1);
}

void	environnement_update(t_everything *all)
{
	update_animations(all, clock());
}
