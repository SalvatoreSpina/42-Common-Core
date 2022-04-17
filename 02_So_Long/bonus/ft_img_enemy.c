/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:34:47 by sspina            #+#    #+#             */
/*   Updated: 2021/11/18 14:08:48 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_enemy1(t_render_v **vars, t_game_map **map)
{
	char		*bg;
	static void	*img;
	int			pos[2];

	bg = ENEMY1;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, bg, &pos[0], &pos[1]);
	(*map)->enemy = img;
}

void	ft_enemy2(t_render_v **vars, t_game_map **map)
{
	char		*bg;
	static void	*img;
	int			pos[2];

	bg = ENEMY2;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, bg, &pos[0], &pos[1]);
	(*map)->enemy = img;
}
