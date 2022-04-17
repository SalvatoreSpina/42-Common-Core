/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:21:38 by sspina            #+#    #+#             */
/*   Updated: 2021/11/18 14:21:40 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_check_length(t_game_map *game_map)
{
	int	line_l;
	int	should_l;
	int	is_l;
	int	cl;

	cl = 0;
	should_l = 0;
	is_l = 0;
	line_l = ft_strlen(game_map->map_data[0]);
	while (cl <= game_map->map_height)
	{
		is_l += ft_strlen(game_map->map_data[(cl)]);
		should_l += line_l;
		cl++;
	}
	return (is_l == should_l);
}

static int	ft_check_exit(t_game_map *game_map)
{
	int		exit_count;
	int		count;
	char	*line;

	count = 0;
	exit_count = 0;
	while (count <= game_map->map_height)
	{
		line = game_map->map_data[count];
		if (ft_strchr(line, 'E'))
			exit_count++;
		count++;
	}
	return (exit_count);
}

static unsigned long	ft_check_player(t_game_map *game_map)
{
	int		count;
	char	*position;
	char	*position2;
	char	*line;

	position = 0;
	count = 0;
	position2 = 0;
	while (count <= game_map->map_height)
	{
		line = game_map->map_data[count];
		if (position)
			position2 = ft_singlelinechr(line, 'P');
		if (!position)
			position = ft_singlelinechr(line, 'P');
		if (position2)
			return (0);
		count++;
	}
	return (!!position);
}

static int	ft_check_walls(t_game_map *game_map)
{
	int		count;
	int		flag;
	char	*temp;

	count = 0;
	flag = 1;
	if (!ft_check_is_wall(game_map->map_data[0]))
		return (0);
	if (!ft_check_is_wall(game_map->map_data[game_map->map_height]))
		return (0);
	while (count <= game_map->map_height)
	{
		temp = game_map->map_data[count];
		if (temp[0] != '1')
			flag = 0;
		if (temp[ft_strlen(temp) - 1] != '1')
			flag = 0;
		count++;
	}
	return (flag);
}

int	ft_check_map_data(t_game_map **game_map)
{
	if (!ft_check_length((*game_map)))
		return (0);
	if (!ft_check_walls((*game_map)))
		return (0);
	if (!ft_check_player((*game_map)))
		return (0);
	if (ft_check_exit((*game_map)) == 0)
		return (0);
	if (ft_max_score((*game_map)) == 0)
		return (0);
	if (!ft_check_map_file((*game_map)))
		return (0);
	return (1);
}
