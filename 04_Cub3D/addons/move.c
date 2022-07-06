/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:59:23 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 20:47:35 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Default spawn is N, so Andreino you rotate if needed

int	spawn_dir(t_everything *all)
{
	double	radians;

	radians = 0;
	if (all->info.spawn_dir == 'N')
		return (0);
	else if (all->info.spawn_dir == 'W')
		radians = M_PI / 2;
	else if (all->info.spawn_dir == 'S')
		radians = M_PI;
	else if (all->info.spawn_dir == 'E')
		radians = 1.5 * M_PI;
	rotate(all, radians);
	return (0);
}

// Check move (read the name lol)

int	update_and_draw(t_everything *all)
{
	if (all->ray.forward)
		all->redraw = move_player(all, all->ray.dir_x, all->ray.dir_y);
	if (all->ray.backwards)
		all->redraw = move_player(all, -all->ray.dir_x, -all->ray.dir_y);
	if (all->ray.left)
		all->redraw = move_player(all, -all->ray.plane_x, -all->ray.plane_y);
	if (all->ray.right)
		all->redraw = move_player(all, all->ray.plane_x, all->ray.plane_y);
	if (all->ray.rot_right)
		all->redraw = rotate(all, -all->ray.const_rad * all->ray.rot_right);
	if (all->ray.rot_left)
		all->redraw = rotate(all, all->ray.const_rad * all->ray.rot_left);
	if (all->ray.open_door)
	{
		all->redraw = switch_door(all);
		all->ray.open_door = 0;
	}
	environnement_update(all);
	draw(all);
	display(all);
	return (1);
}

// Move player (man read the name again)

int	move_player(t_everything *all, double x, double y)
{
	int	st;

	st = 0;
	if (all->info.map[(int)(all->ray.our_x + x * all->ray.step_size)]
		[(int)(all->ray.our_y)] == '0'
		|| all->info.map[(int)(all->ray.our_x + x * all->ray.step_size)]
		[(int)(all->ray.our_y)] == 'A')
	{
		all->ray.our_x += x * (all->ray.step_size - 0.01);
		st = 1;
	}
	if (all->info.map[(int)(all->ray.our_x)][(int)
		(all->ray.our_y + y * all->ray.step_size)] == '0'
		|| all->info.map[(int)(all->ray.our_x)]
		[(int)(all->ray.our_y + y * all->ray.step_size)] == 'A')
	{
		all->ray.our_y += y * (all->ray.step_size - 0.01);
		st = 1;
	}
	return (st);
}
// Rotate by grad. Remember that 90° = π/2 rad

int	rotate(t_everything *all, double radians)
{
	double	prev_dir_x;
	double	prev_plane_x;

	prev_dir_x = all->ray.dir_x;
	all->ray.dir_x = all->ray.dir_x * cos(radians)
		- all->ray.dir_y * sin(radians);
	all->ray.dir_y = prev_dir_x * sin(radians) + all->ray.dir_y * cos(radians);
	prev_plane_x = all->ray.plane_x;
	all->ray.plane_x = all->ray.plane_x * cos(radians)
		- all->ray.plane_y * sin(radians);
	all->ray.plane_y = prev_plane_x * sin(radians)
		+ all->ray.plane_y * cos(radians);
	all->ray.rot_right = 0.0f;
	all->ray.rot_left = 0.0f;
	return (1);
}
