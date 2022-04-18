/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:07:06 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:33 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(t_render_v **vars, void *p, int x, int y)
{
	if ((*vars) && p)
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, p, x, y);
}
