/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:46:44 by sspina            #+#    #+#             */
/*   Updated: 2022/06/23 15:50:48 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_int(char *full_file, unsigned int *le_int, char *id)
{
	char	*line;

	line = line_creator(full_file, id);
	if (!line)
	{
		free(line);
		*le_int = 0;
		return (0);
	}
	*le_int = ft_atoi(line);
	if (*le_int < 0 || *le_int > 100)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	parse_color_unrequired(char *full_file, unsigned int *color, char *id)
{
	char	*line;
	char	**split;
	t_color	color_s;

	ft_bzero(&color_s, sizeof(t_color));
	line = line_creator(full_file, id);
	if (!line)
	{
		free(line);
		*color = 0;
		return (0);
	}
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
