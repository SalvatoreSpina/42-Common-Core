/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:08:57 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:06:55 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// MLX is good but i'm better
//                       -Sun Tzu

/*
    Just_image_to_windows but left corner.
    Called 'a' instead of all because lines too long lmao
	
*/

int	show_img(t_everything *a)
{
	mlx_put_image_to_window(a->image.mlx, a->image.win, a->image.img, 0, 0);
	mlx_put_image_to_window(a->image.mlx, a->image.win,
		a->minimap.img, 60, 60);
	return (0);
}

//	Creates new image and put in xpm

int	file_to_img(t_image *img, char *filename)
{
	img->mlx = mlx_init();
	if (!(img->mlx))
		return (error_msg("Creating mlx pointer failed"));
	if (ft_strstr(filename, ".xpm"))
		img->img = mlx_xpm_file_to_image(img->mlx, filename, &(img->width),
				&(img->height));
	if (!(img->img))
	{
		printf("%s does not exist.\n", filename);
		return (1);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	return (0);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < img->width && y < img->height && y >= 0 && x >= 0)
	{
		dst = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
