/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:57:03 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:06:06 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

int	main(int argc, char *argv[])
{
	t_everything	all;

	ft_bzero(&all, sizeof(all));
	if (init_input(&all, argc, argv[1])
		OR init_textures(&all)
		OR init_mlx(&all, argv[1])
		OR init_raycaster(&all)
		OR minimap_init(&all))
		return (1);
	draw_img(&all);
	show_img(&all);
	mlx_hook(all.image.win, BOOMBOOM, 0, &destroy_window, &all);
	mlx_hook(all.image.win, KB_PRESS, 0, &key_pressed, &all);
	mlx_hook(all.image.win, KB_RELEASE, 0, &key_released, &all);
	mlx_hook(all.image.win, 4, 1L << 8, &mouse_pressed, &all);
	mlx_hook(all.image.win, 6, 1L << 8, (int (*)()) & mouse_movement, &all);
	mlx_loop_hook(all.image.mlx, &update_and_draw, &all);
	mlx_loop(all.image.mlx);
	return (0);
}
