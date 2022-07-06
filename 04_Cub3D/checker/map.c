/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:25:12 by sspina            #+#    #+#             */
/*   Updated: 2022/06/28 16:19:13 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	Find beginning of the map

int	find_map(char *full_file)
{
	int	check;
	int	i;

	i = ft_strlen(full_file) - 1;
	check = 1;
	while (full_file[i] && i > 0)
	{
		i--;
		if (full_file[i] == '\n' AND !is_map_line(full_file, i))
			return (i);
	}
	return (-1);
}

//	Check upper and lower row of map for gaps

int	check_row(char **map, int y_pos)
{
	int	x;
	int	rowlen;

	x = 0;
	rowlen = ft_strlen(map[y_pos]);
	while (x < rowlen)
	{
		if (ft_inset("0NEWS", map[y_pos][x]))
			return (1);
		x++;
	}
	return (0);
}

//	Check first and last char in row for gaps

int	check_firstlast(char **map, int height)
{
	int	y;
	int	rowlen;

	y = 0;
	while (y < height)
	{
		rowlen = ft_strlen(map[y]);
		if (ft_inset("0NEWS", map[y][0])
			|| ft_inset("0NEWS", map[y][rowlen - 1]))
			return (1);
		y++;
	}
	return (0);
}

//	Check chars next to current char in all directions

int	check_spots(char **map, int x, int y)
{
	if (ft_inset("0NESW", map[y][x]) &&
				(is_notmap(map[y - 1][x]) ||
				is_notmap(map[y + 1][x]) ||
				is_notmap(map[y][x - 1]) ||
				is_notmap(map[y][x + 1]) ||
				is_notmap(map[y - 1][x - 1]) ||
				is_notmap(map[y + 1][x + 1]) ||
				is_notmap(map[y - 1][x + 1]) ||
				is_notmap(map[y + 1][x - 1])))
		return (1);
	else
		return (0);
}

//	Check whether map is enclosed by walls

int	check_map(t_info *info)
{
	int	x;
	int	y;
	int	rowlen;

	if (check_row(info->map, 0)
		|| check_row(info->map, info->map_height - 1)
		|| check_firstlast(info->map, info->map_height))
		return (1);
	y = 1;
	while (y < info->map_height - 1)
	{
		x = 1;
		rowlen = ft_strlen(info->map[y]);
		while (x < rowlen - 1)
		{
			if (check_spots(info->map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
