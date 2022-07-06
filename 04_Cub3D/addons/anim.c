/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:04:56 by achansel          #+#    #+#             */
/*   Updated: 2022/06/30 18:52:39 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* First loop is to get size, second one is to read the images */
int	anim_get_frame_count(char *path)
{
	char	current_file[1024];
	int		fd;
	int		fc;

	fc = 0;
	ft_strlcpy(current_file, path, 1024);
	ft_strlcat(current_file, "_", 1024);
	while (1)
	{
		ft_itoa(&current_file[ft_strlen(path) + 1], fc);
		ft_strlcat(current_file, ".xpm", 1024);
		fd = open(current_file, O_RDONLY);
		if (fd == -1)
			break ;
		close(fd);
		fc++;
	}
	return (fc);
}

t_image	*anim_get_frames(t_everything *all, char *path,
	unsigned int *frame_count)
{
	char			current_file[1024];
	unsigned int	i;
	t_image			*frames;

	(void) all;
	i = 0;
	*frame_count = anim_get_frame_count(path);
	if (!*frame_count)
		return (NULL);
	frames = malloc(sizeof(t_image) * *frame_count);
	ft_strlcpy(current_file, path, 1024);
	ft_strlcat(current_file, "_", 1024);
	while (i < *frame_count)
	{
		ft_itoa(&current_file[ft_strlen(path) + 1], i);
		ft_strlcat(current_file, ".xpm", 1024);
		file_to_img(&frames[i], current_file);
		i++;
	}
	return (frames);
}

void	animator_init(t_animable *a, t_image *frames, unsigned int fc, int ft)
{
	a->last_update = 0;
	a->frame_time = ft;
	a->frame_pointer = 0;
	a->frame_count = fc;
	a->frames = frames;
}
