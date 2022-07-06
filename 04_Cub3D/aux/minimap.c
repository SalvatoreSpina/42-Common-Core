/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:58:03 by achansel          #+#    #+#             */
/*   Updated: 2022/07/05 20:53:24 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MINIMAP_WALL_COLOR 0x40FF0000
#define MINIMAP_OTHER_COLOR 0x80FFFFFF
#define MINIMAP_TSZ 10
#define MINIMAP_PLAYER_SZ  5 //(MINIMAP_TSZ / 2)
#define MINIMAP_PLAYER_C 0x000000FF

int	minimap_init(t_everything *all)
{
	int	x;
	int	y;

	all->minimap.mlx = all->image.mlx;
	all->minimap.win = all->image.win;
	all->minimap.img = mlx_new_image(all->image.mlx,
			MINIMAP_TSZ * all->info.map_width,
			MINIMAP_TSZ * all->info.map_height);
	all->minimap.addr = mlx_get_data_addr(all->minimap.img,
			&all->minimap.bits_per_pixel, &all->minimap.line_length,
			&all->minimap.endian);
	all->minimap.width = MINIMAP_TSZ * all->info.map_width;
	all->minimap.height = MINIMAP_TSZ * all->info.map_height;
	y = 0;
	while (y < all->minimap.height)
	{
		x = 0;
		while (x < all->minimap.width)
		{
			put_pixel(&all->minimap, x++, y, 0xFF000000);
		}
		y++;
	}
	return (0);
}

void	minimap_colored_rect(t_image *img, int o[2], int sz, int col)
{
	int	x;
	int	y;

	x = 0;
	while (x < sz)
	{
		y = 0;
		while (y < sz)
		{
			put_pixel(img, o[0] + x, o[1] + y++, col);
		}
		x++;
	}
}

// Verifier le carre du joueur
void	minimap_generate(t_everything *all)
{
	int	x;
	int	y;

	y = -1;
	while (++y < all->info.map_height)
	{
		x = -1;
		while (all->info.map[y][++x])
		{
			if (all->info.map[y][x] == '1' || all->info.map[y][x] == 'C'
					|| all->info.map[y][x] == 'A')
			{
				minimap_colored_rect(&all->minimap, (int [2]){MINIMAP_TSZ * x,
					y * MINIMAP_TSZ}, MINIMAP_TSZ, MINIMAP_WALL_COLOR);
			}
			else if (all->info.map[y][x] == '0')
			{
				minimap_colored_rect(&all->minimap, (int [2]){MINIMAP_TSZ * x,
					y * MINIMAP_TSZ}, MINIMAP_TSZ, MINIMAP_OTHER_COLOR);
			}
		}
	}
	minimap_colored_rect(&all->minimap, (int [2]){(int)
		(all->ray.our_y * MINIMAP_TSZ), (int)(all->ray.our_x * MINIMAP_TSZ)},
		MINIMAP_PLAYER_SZ, MINIMAP_PLAYER_C);
}
