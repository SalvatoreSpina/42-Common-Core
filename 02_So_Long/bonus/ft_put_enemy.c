/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:10:16 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:03 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_enemy(t_game_map **map)
{
	static int	enemy_pos[2];
	static int	enemy_set = 0;

	while (enemy_set == 0)
	{
		enemy_pos[1] = ((ft_pseudordm() + 1) % (*map)->map_height);
		enemy_pos[0] = ((ft_pseudordm() + 1) % (*map)->map_length);
		if (!(enemy_pos[0] == ((*map)->player_position_x / TILE_WIDTH)))
			enemy_set++;
		if (!(enemy_pos[1] == ((*map)->player_position_y / TILE_WIDTH)))
			enemy_set++;
		(*map)->enemy_pos = enemy_pos;
		(*map)->enemy_set = 1;
	}
	(*map)->enemy_pos = enemy_pos;
}
