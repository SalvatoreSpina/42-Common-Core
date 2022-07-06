/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:51:43 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 19:57:04 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*
	- That formula calculate the X of where the camera is
		(if you try to increment 2, you will see strechted and weird)
	- You put the ray direction with these two formulas
	- You save the box of the map we're in (cause it's useful for walls)
*/
void	set_ray_pos(t_everything *all, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)all->info.x_size - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->our_x;
	ray->map_y = (int)ray->our_y;
}

/*
	- You start with a basic delta fromula dist and no hit
	- You calculate the lengths from a side to another (y or y)
	- Then you calculate the steps dist (look at expl.txt)
*/
void	set_ray_len(t_ray *ray)
{
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->our_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->our_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->our_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->our_y) * ray->delta_dist_y;
	}
}

/*
	If you don't hit wall, you jump 1 square and check again. 
	Give back values for wall (side, and a positive or negative)
*/
void	perform_dda(t_everything *all, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (all->info.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

/*
	- If no side, you calculate the total dist with that formula
	- Otherwise it's the same with x and y swapped (cause it's sidewall)
	- I calculate the height of the wall just dividing y_size (the height)
	- Then you put the two extremis (random formula)
	- You put some limit (0 and y_size) cause you don't write outside window
*/
void	set_projection(t_ray *ray, t_info *info)
{
	if (ray->side == 0)
		ray->total_wall_dist = (ray->map_x - ray->our_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->total_wall_dist = (ray->map_y - ray->our_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(info->y_size / ray->total_wall_dist);
	ray->draw_start = -ray->line_height / 2 + info->y_size / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + info->y_size / 2;
	if (ray->draw_end >= info->y_size)
		ray->draw_end = info->y_size - 1;
}
