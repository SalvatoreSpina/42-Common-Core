/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:06:25 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:01 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_window_height(t_game_map *game_map)
{
	return (((game_map->map_height) + 1) * TILE_WIDTH);
}

int	ft_window_width(t_game_map *game_map)
{
	return ((game_map->map_length) * TILE_WIDTH);
}

int	ft_whc(t_game_map *game_map)
{
	return ((((game_map->map_height) + 1) * TILE_WIDTH) / 2);
}

int	ft_wwc(t_game_map *game_map)
{
	return (((game_map->map_length) * TILE_WIDTH) / 2);
}
