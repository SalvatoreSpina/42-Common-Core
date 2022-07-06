/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:11:29 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 17:30:41 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_res(int *size, char type)
{
	if (type == 'x')
		*size = WWIDTH;
	if (type == 'y')
		*size = WHEIGHT;
	return (0);
}

// Saves rgb color as an unsigned int value

int	parse_color(char *full_file, unsigned int *color, char *id)
{
	char	*line;
	char	**split;
	t_color	color_s;

	ft_bzero(&color_s, sizeof(t_color));
	line = line_creator(full_file, id);
	if (!line)
		return (error_msg("RGB not found"));
	split = ft_split(line, ',');
	if (check_rgb(split, &color_s))
	{
		free_bi_dimensional(split);
		free(line);
		return (1);
	}
	free_bi_dimensional(split);
	free(line);
	*color = create_rgb(color_s.r, color_s.g, color_s.b);
	return (0);
}

//	Save map in 2d array

int	parse_map(t_info *info, char *full_file)
{
	int		start_index;
	int		i;
	int		width;

	i = 0;
	start_index = find_map(full_file);
	if (start_index == -1)
		return (error_msg("Invalid map"));
	info->start = full_file + start_index;
	info->map = ft_split(info->start, '\n');
	while (info->map[info->map_height])
		info->map_height++;
	while (i < info->map_height)
	{
		width = ft_strlen(info->map[i]);
		if (width > info->map_width)
			info->map_width = width;
		i++;
	}
	if (check_spawn(info))
		return (error_msg("Make sure there is one spawn position in map!"));
	if (check_map(info))
		return (error_msg("Map must be closed/surrounded by walls!"));
	return (0);
}

// Saves paths as strings

int	parse_tex(t_info *info)
{
	info->no_path = line_creator(info->full_file, "NO ");
	info->so_path = line_creator(info->full_file, "SO ");
	info->we_path = line_creator(info->full_file, "WE ");
	info->ea_path = line_creator(info->full_file, "EA ");
	if (!(info->no_path) || !(info->so_path)
		|| !(info->we_path) || !(info->ea_path))
		return (error_msg("Enter path for every texture"));
	return (0);
}

/*
	Saves cub file in one long string and calls other functions to parse all
	parts of the information in the cub file. This information is saved in the
	t_info info struct.
*/
int	parse_all(int fd, t_info *info)
{
	if (read_everything(fd, &(info->full_file)) == -1)
		return (error_msg("Error while reading the file"));
	if (parse_res(&(info->x_size), 'x')
		|| parse_res(&(info->y_size), 'y')
		|| parse_color(info->full_file, &(info->f_color), "F ")
		|| parse_color(info->full_file, &(info->c_color), "C ")
		|| parse_color_unrequired(info->full_file, &(info->fog_color), "FC ")
		|| parse_int(info->full_file, &(info->fog_enabled), "FE ")
		|| parse_map(info, info->full_file)
		|| get_spawn_pos(info)
		|| parse_tex(info))
		return (free_all(info, 1));
	free(info->full_file);
	success_msg("The file is correctly parsed!");
	return (0);
}		
