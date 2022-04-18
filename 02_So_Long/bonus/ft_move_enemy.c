/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:08:59 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:28 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_y(int change, t_game_map **map)
{
	if (change < 0)
		return (0);
	if (change >= (*map)->map_height)
		return (0);
	return (1);
}

static int	is_valid_x(int change, t_game_map **map)
{
	if (change < 0)
		return (0);
	if (change >= (*map)->map_length)
		return (0);
	return (1);
}

void	ft_move_enemy(t_game_map **map)
{
	int	change;
	int	dir;
	int	ho;

	change = (ft_pseudordm() + (*map)->steps) % 10;
	dir = ft_pseudordm() % 2;
	ho = (*map)->enemy_pos[0];
	if (dir == 1)
		ho = (*map)->enemy_pos[1];
	if (change > 4)
		ho = ho + 1;
	else
		ho = ho - 1;
	if (dir == 1 && is_valid_y(ho, map))
		(*map)->enemy_pos[1] = ho;
	else if (dir == 0 && is_valid_x(ho, map))
		(*map)->enemy_pos[0] = ho;
}
