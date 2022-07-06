/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:16:18 by achansel          #+#    #+#             */
/*   Updated: 2022/07/05 21:07:57 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <pthread.h>

int	draw_img_threaded(t_everything *all)
{
	pthread_t	threads[RENDERER_THREAD_COUNT];
	int			i;

	get_thread_id(true);
	i = 0;
	while (i < RENDERER_THREAD_COUNT)
		pthread_create(&threads[i++], NULL, (void *) draw_img, all);
	i = 0;
	while (i < RENDERER_THREAD_COUNT)
		pthread_join(threads[i++], NULL);
	return (0);
}

void	draw(t_everything *all)
{
	if (all->redraw || all->enemy_redraw)
	{
		draw_img_threaded(all);
		all->redraw = false;
		all->enemy_redraw = false;
	}
}

void	display(t_everything *a)
{
	mlx_put_image_to_window(a->image.mlx, a->image.win, a->image.img, 0, 0);
	mlx_put_image_to_window(a->image.mlx, a->image.win,
		a->minimap.img, 60, 60);
	mlx_put_image_to_window(a->image.mlx, a->image.win,
		a->hands.animator.frames[a->hands.animator.frame_pointer].img,
		WWIDTH - 1280, WHEIGHT - 720);
}
