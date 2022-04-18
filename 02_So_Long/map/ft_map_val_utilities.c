/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_val_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:25:37 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:30 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_is_wall(char *wall)
{
	size_t	count;

	count = 0;
	while (wall[count] == '1')
		count++;
	return (ft_strlen(wall) == count);
}

int	ft_check_filename(char *file_name)
{
	int			len;
	const char	*start;

	len = ft_strlen(file_name);
	start = (const char *) &file_name[(len - 4)];
	if (ft_strncmp(start, ".ber", 4) == 0)
		return (1);
	return (0);
}

void	ft_find_player(t_game_map *game_map, int *x, int *y)
{
	int		count;
	char	*line;
	int		x_pos;

	count = 0;
	x_pos = 0;
	while (count <= game_map->map_height)
	{
		line = game_map->map_data[count];
		if (ft_strchr(line, 'P'))
		{
			*y = (count * TILE_WIDTH);
			while (line[x_pos] != 'P')
				x_pos++;
			*x = (x_pos * TILE_WIDTH);
		}
		count++;
	}
}

char	*ft_singlelinechr(char *line, char c)
{
	char	*p;
	char	*pr;

	p = ft_strchr(line, c);
	pr = ft_strrchr(line, c);
	if (p == pr && (pr && p))
		return (p);
	return (NULL);
}
