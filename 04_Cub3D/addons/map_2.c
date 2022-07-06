/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:17:42 by achansel          #+#    #+#             */
/*   Updated: 2022/07/05 19:44:54 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int	spawn_guns(t_everything *all, t_info *info)
{
	int	y;
	int	x;
	int	no;

	no = 0;
	y = 0;
	while (y < info->map_height)
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == 'G')
			{
				if (no < 1024)
					init_gun_sprite(all, &all->sprites[no++], y, x);
			}
			x++;
		}
		y++;
	}
	all->sprites_len = no;
	return (0);
}
*/
bool	is_map_line(char *line, int idx)
{
	idx--;
	if (line[idx] == '\n')
		return (false);
	while (idx >= 0 AND line[idx] != '\n')
		idx--;
	while (line[++idx] != '\n' && line[idx] != '\0')
	{
		if (!ft_inset("10ACNEWS \n", line[idx]))
		{
			return (false);
		}
	}
	return (true);
}
