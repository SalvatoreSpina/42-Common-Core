/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:43:33 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:03:40 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check input

int	init_input(t_everything *all, int argc, char *cub_file)
{
	int		fd;

	if (argc != 2)
		return (error_msg("Wrong number of arguments\n"));
	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		return (error_msg("Wrong file!\n"));
	if (parse_all(fd, &(all->info)))
		return (1);
	return (0);
}

//	Save texture to struct.

int	init_textures(t_everything *all)
{
	if (file_to_img(&(all->tex.n_img), all->info.no_path)
		|| file_to_img(&(all->tex.s_img), all->info.so_path)
		|| file_to_img(&(all->tex.e_img), all->info.ea_path)
		|| file_to_img(&(all->tex.w_img), all->info.we_path))
		return (free_all(&(all->info), 0));
	free(all->info.no_path);
	free(all->info.so_path);
	free(all->info.we_path);
	free(all->info.ea_path);
	return (0);
}

//	Create windows and IMG

int	init_mlx(t_everything *all, char *map_name)
{
	char	*window_title;

	all->image.mlx = mlx_init();
	if (!(all->image.mlx))
	{
		free_bi_dimensional(all->info.map);
		return (error_msg("Creating mlx pointer failed"));
	}
	window_title = ft_strjoin("cub3d: ", map_name);
	all->image.win = mlx_new_window(all->image.mlx, all->info.x_size,
			all->info.y_size, window_title);
	all->image.img = mlx_new_image(all->image.mlx, all->info.x_size,
			all->info.y_size);
	all->image.addr = mlx_get_data_addr(all->image.img,
			&all->image.bits_per_pixel,
			&all->image.line_length, &all->image.endian);
	all->image.width = all->info.x_size;
	all->image.height = all->info.y_size;
	free(window_title);
	return (0);
}

/*
	Initialise various values. 
	Step_size is actually the speed.
	Const rad the sensibility.
*/

int	init_raycaster(t_everything *all)
{
	all->ray.our_x = all->info.y_spawn + 0.5;
	all->ray.our_y = all->info.x_spawn + 0.5;
	all->ray.dir_x = -1;
	all->ray.dir_y = 0;
	all->ray.plane_x = 0;
	all->ray.plane_y = 0.66;
	all->ray.step_size = 0.10;
	all->ray.const_rad = M_PI / 80;
	all->ray.forward = 0;
	all->ray.backwards = 0;
	all->ray.left = 0;
	all->ray.right = 0;
	all->ray.rot_left = 0;
	all->ray.rot_right = 0;
	all->ray.sprite_hit_x = -1;
	all->ray.sprite_hit_y = -1;
	all->controller.mouse_grabbed = 0;
	all->controller.first_input = 1;
	spawn_dir(all);
	return (0);
}

int	init_environnement(t_everything *all)
{
	int	i;

	i = 0;
	ft_bzero(all->animables, sizeof(all->animables));
	all->animables_len = 0;
	all->redraw = false;
	all->enemy_redraw = true;
	return (0);
}
