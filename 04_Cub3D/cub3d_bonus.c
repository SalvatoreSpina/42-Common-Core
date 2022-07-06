/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:57:03 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:05:57 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

/* Sets the working directory to where cub3d is */
int	set_working_directory(char *binary_path)
{
	char	path[PATH_MAX + 1];

	ft_strlcpy(path, binary_path, PATH_MAX);
	if (ft_strrchr(path, '/'))
	{
		path[ft_strrchr(path, '/') - path] = '\0';
		chdir(path);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_everything	all;

	ft_bzero(&all, sizeof(all));
	if (init_environnement(&all)
		|| init_player(&all)
		|| init_input(&all, argc, argv[1])
		|| set_working_directory(argv[0])
		|| init_textures(&all)
		|| init_mlx(&all, argv[1])
		|| init_raycaster(&all)
		|| minimap_init(&all)
		|| draw_img_threaded(&all)
		|| show_img(&all))
		return (1);
	mlx_hook(all.image.win, BOOMBOOM, 0, &destroy_window, &all);
	mlx_hook(all.image.win, KB_PRESS, 0, &key_pressed, &all);
	mlx_hook(all.image.win, KB_RELEASE, 0, &key_released, &all);
	mlx_hook(all.image.win, 4, 1L << 8, &mouse_pressed, &all);
	mlx_hook(all.image.win, 6, 1L << 8, (int (*)()) & mouse_movement, &all);
	mlx_loop_hook(all.image.mlx, &update_and_draw, &all);
	mlx_loop(all.image.mlx);
	return (0);
}
