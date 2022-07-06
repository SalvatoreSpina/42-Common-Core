/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:25:38 by sspina            #+#    #+#             */
/*   Updated: 2022/01/23 14:19:59 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Put background

void	put_pix_bg(t_everything *all, int y, int color)
{
	int	i;

	i = 0;
	while (i < all->info.x_size)
	{
		put_pixel((&all->image), i, y, color);
		i++;
	}
}

// Check border

int	is_notmap(char c)
{
	if (!c)
		return (1);
	if (c == ' ' || c == '\n')
		return (1);
	else
		return (0);
}

// Free the map, if 2nd arg is true free full_fule

int	free_all(t_info *info, int stage)
{
	if (stage)
		free(info->full_file);
	free(info->no_path);
	free(info->so_path);
	free(info->we_path);
	free(info->ea_path);
	free_bi_dimensional(info->map);
	return (1);
}
