/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   informations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:00:10 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:03:26 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	Checks whether rgb color input is valid

int	check_rgb(char **split, t_color *color_s)
{
	int	i;

	if (!split || !split[2])
		return (error_msg("Please enter a RGB value"));
	i = 0;
	while (split[i])
	{
		if (!(theres_a_digit(split[i])))
			return (error_msg("Please enter a RGB value"));
		if (!(check_only_digits(split[i])))
			return (error_msg("Please enter a RGB value (digits only!)"));
		i++;
	}
	color_s->r = ft_atoi(split[0]);
	color_s->g = ft_atoi(split[1]);
	color_s->b = ft_atoi(split[2]);
	if (color_s->r > 255 || color_s->g > 255 || color_s->b > 255
		|| color_s->r < 0 || color_s->g < 0 || color_s->b < 0)
		return (error_msg("RGB values must be within 0 and 255"));
	return (0);
}

// Check only one spawn	

int	check_spawn(t_info *info)
{
	int	index;

	index = ft_set_in_set(info->start, "NESW");
	if (index == -1)
		return (1);
	index = ft_set_in_set(info->start + index + 1, "NESW");
	if (index != -1)
		return (1);
	return (0);
}

//	Find the spawn, save coordinate and then replace with 0 (so it's empty)
int	get_spawn_pos(t_info *info)
{
	int	y_index;
	int	x_index;

	info->map_height = rows_counter(info->map);
	y_index = 0;
	while (y_index < info->map_height)
	{
		x_index = ft_set_in_set(info->map[y_index], "NESW");
		if (x_index >= 0)
			break ;
		y_index++;
	}
	if (x_index >= 0)
	{
		info->x_spawn = x_index;
		info->y_spawn = y_index;
		info->spawn_dir = info->map[y_index][x_index];
		info->map[info->y_spawn][info->x_spawn] = '0';
		return (0);
	}
	return (error_msg("Error saving spawn position in map"));
}
