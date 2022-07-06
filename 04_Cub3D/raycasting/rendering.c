/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:51:15 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:14:09 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <pthread.h>
#include <string.h>

//	Draw background
//	For the upper half you put the ceiling color
//	By changing color, you can make a fake gradiant that goes to black

int	draw_bg(t_everything *all, int min, int max)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < all->info.y_size / 2)
	{
		color = blend_color(all->info.c_color, all->info.fog_color,
				get_blending_by_dst(all, (all->info.y_size / 2.0f - y) * 2));
		x = min - 1;
		while (++x < max)
			put_pixel((&all->image), x, y, color);
		y++;
	}
	while (y < all->info.y_size)
	{
		color = blend_color(all->info.f_color, all->info.fog_color,
				get_blending_by_dst(all, (y - all->info.y_size / 2.0f) * 2));
		x = min - 1;
		while (++x < max)
			put_pixel((&all->image), x, y, color);
		y++;
	}
	return (0);
}

//	Sets coordinates of texture image to use for wall

int	set_tex(t_everything *all, t_ray *r, t_image wall_img)
{
	if (r->side == 0)
		r->wall_x = r->our_y + r->total_wall_dist
			* r->ray_dir_y;
	else
		r->wall_x = r->our_x + r->total_wall_dist
			* r->ray_dir_x;
	r->wall_x -= floor((r->wall_x));
	r->x_tex = (int)(r->wall_x * (double)wall_img.width);
	if ((r->side == 0 && r->ray_dir_x > 0)
		|| (r->side == 1 && r->ray_dir_y < 0))
		r->x_tex = wall_img.width - r->x_tex;
	r->y_tex = 0;
	r->y_tex_step = wall_img.height / (double)r->line_height;
	if (r->line_height > all->info.y_size)
		r->y_tex = (r->line_height - all->info.y_size)
			* r->y_tex_step / 2;
	return (0);
}

int	draw_tex(t_everything *all, t_ray *r, t_image wall_img, int x)
{
	char	*dst;
	int		y_wall;
	int		color;

	set_tex(all, r, wall_img);
	y_wall = r->draw_start;
	while (y_wall <= r->draw_end)
	{
		dst = wall_img.addr + ((int)(r->y_tex) % wall_img.height
				* wall_img.line_length + r->x_tex % wall_img.width
				* (wall_img.bits_per_pixel / 8));
		color = blend_color(*(unsigned int *)dst, all->info.fog_color,
				get_blending_by_dst(all, r->draw_end - r->draw_start));
		put_pixel(&(all->image), x, y_wall, color);
		y_wall++;
		r->y_tex += r->y_tex_step;
	}
	return (0);
}

//	Loops through vertical lines to be drawn in image
//	Does raycasting calc and place textures on walls

void	draw_img(t_everything *all)
{
	int		x;

	draw_bg(all, 0, all->info.x_size - 1);
	x = 0;
	while (x < all->info.x_size)
	{
		set_ray_pos(all, &(all->ray), x);
		set_ray_len(&(all->ray));
		perform_dda(all, &(all->ray));
		set_projection(&(all->ray), &(all->info));
		if (all->ray.side == 0 && all->ray.step_x == 1)
			draw_tex(all, &(all->ray), all->tex.n_img, x);
		if (all->ray.side == 0 && all->ray.step_x == -1)
			draw_tex(all, &(all->ray), all->tex.s_img, x);
		if (all->ray.side == 1 && all->ray.step_y == 1)
			draw_tex(all, &(all->ray), all->tex.w_img, x);
		if (all->ray.side == 1 && all->ray.step_y == -1)
			draw_tex(all, &(all->ray), all->tex.e_img, x);
		x++;
	}
	minimap_generate(all);
}
