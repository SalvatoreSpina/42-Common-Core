/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:16:23 by achansel          #+#    #+#             */
/*   Updated: 2022/07/05 21:03:49 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_line(char *line, int idx)
{
	idx--;
	if (line[idx] == '\n')
		return (false);
	while (idx >= 0 AND line[idx] != '\n')
		idx--;
	while (line[++idx] != '\n' && line[idx] != '\0')
	{
		if (!ft_inset("10NEWS \n", line[idx]))
		{
			return (false);
		}
	}
	return (true);
}

int	spawn_guns(t_everything *all, t_info *info)
{
	(void) all;
	(void) info;
	return (0);
}
