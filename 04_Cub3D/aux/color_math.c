/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:09:28 by sspina            #+#    #+#             */
/*   Updated: 2022/06/30 21:30:08 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

inline int	blend_color(const int src_col, int dst_col, float blend)
{
	int	r;
	int	g;
	int	b;

	if (blend >= 1.0f)
		return (dst_col);
	if (blend <= 0.0f)
		return (src_col);
	r = get_r(src_col) + (get_r(dst_col) - get_r(src_col)) * blend;
	g = get_g(src_col) + (get_g(dst_col) - get_g(src_col)) * blend;
	b = get_b(src_col) + (get_b(dst_col) - get_b(src_col)) * blend;
	return (create_rgb(r, g, b));
}

inline float	get_blending_by_dst(t_everything *all, int dist)
{
	float	density;
	float	dist_inverse;
	float	g;

	if (all->info.fog_enabled == 0)
		return (0.0f);
	dist_inverse = all->info.y_size - dist;
	g = dist_inverse / 2000 + 0.3f;
	density = (float)(all->info.fog_enabled);
	return (((dist_inverse - 240)
			/ (all->info.y_size - 240) + 0.2 * density) * density);
}
