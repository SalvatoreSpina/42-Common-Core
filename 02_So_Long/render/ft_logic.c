/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:59:33 by sspina            #+#    #+#             */
/*   Updated: 2021/11/18 13:02:05 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_game_end(t_game_map *game_map)
{
	return (game_map->max_score == game_map->game_score);
}

int	ft_max_score(t_game_map *game_map)
{
	int		score;
	int		count_x;
	int		count_y;

	score = 0;
	count_x = 0;
	count_y = 0;
	while (count_y <= game_map->map_height)
	{
		count_x = 0;
		while (game_map->map_data[count_y][count_x])
		{
			if (game_map->map_data[count_y][count_x] == 'C')
				score++;
			count_x++;
		}
		count_y++;
	}
	return (score);
}
