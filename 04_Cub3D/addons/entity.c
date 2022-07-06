/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:05:39 by achansel          #+#    #+#             */
/*   Updated: 2022/07/05 21:01:02 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	init_gun_sprite(t_everything *all, t_sprite *s, int xnew, int ynew)
{
	t_image			*frames;
	unsigned int	frame_count;

	frames = anim_get_frames(all, "textures/sprite/gun/gun", &frame_count);
	if (!frames)
	{
		error_msg("Couldn't load gun sprite");
		exit(1);
	}
	animator_init(&s->animator, frames,
		frame_count, 50);
	s->x = xnew;
	s->y = ynew;
	if (all->animables_len < 1024)
		all->animables[all->animables_len++] = &s->animator;
}
*/

int	init_player(t_everything *all)
{
	t_hands	*hands;

	hands = &all->hands;
	hands->idle_frames = anim_get_frames(all,
			"textures/sprite/idle/idle",
			&hands->idle_frames_count);
	if (hands->idle_frames == NULL)
	{
		error_msg("Couldn't load idle frames");
		exit(1);
	}
	hands->idle_frames_time = 70;
	animator_init(&hands->animator, hands->idle_frames,
		hands->idle_frames_count, hands->idle_frames_time);
	all->animables[all->animables_len++] = &hands->animator;
	return (0);
}
/*
void	init_enemy(t_everything *all, t_entity *e, int xnew, int ynew)
{
	e->health = 5;
	e->last_shot = 0;
	e->shot_delay = 0;
	e->shot_damage = 3;
	e->is_shooting = 1;
	e->shooting_frames = anim_get_frames(all,
			"textures/enemy/shooting_frames/",
			&e->shooting_frames_count);
	e->shooting_frames_time = 200;
	e->idle_frames = anim_get_frames(all,
			"textures/enemy/idle_frames/",
			&e->idle_frames_count);
	e->idle_frames_time = 300;
	animator_init(&e->animator, e->idle_frames,
		e->idle_frames_count, e->idle_frames_time);
	e->x = xnew;
	e->y = ynew;
	all->animables[all->animables_len++] = &e->animator;
}

void	init_enemies(t_everything *all)
{
	int	y_index;
	int	x_index;
	int	e_count;

	y_index = 0;
	e_count = 0;
	while (y_index < all->info.map_height)
	{
		x_index = 0;
		while (ft_set_in_set(all->info.map[y_index], "R") != -1)
		{
			init_enemy(all, &(all->enemies[e_count++]), x_index, y_index);
			all->info.map[y_index][x_index] = '0';
			x_index++;
		}
		y_index++;
	}
	all->enemies_len = e_count;
}

void	entity_shoot(t_entity *attack, t_entity *receiver)
{
	receiver->health -= attack->shot_damage;
	attack->animator.frames = attack->idle_frames;
	attack->animator.frame_count = attack->idle_frames_count;
	attack->animator.frame_time = attack->idle_frames_time;
	attack->animator.frame_pointer = 0;
	attack->animator.last_update = clock() * 1000 / CLOCKS_PER_SEC;
}
*/