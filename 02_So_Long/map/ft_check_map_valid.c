/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:22:33 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:28 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_map_file(t_game_map *game_map)
{
	int		counter;
	int		inner_counter;
	char	*line;

	counter = 0;
	inner_counter = 0;
	while (counter <= game_map->map_height)
	{
		inner_counter = 0;
		line = game_map->map_data[counter];
		while (line[inner_counter])
		{
			if (!ft_inset(line[inner_counter], (const char *) "01CEP"))
				return (0);
			inner_counter++;
		}
		counter++;
	}
	return (1);
}
