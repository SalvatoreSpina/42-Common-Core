/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:50:38 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:08:33 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_rgb(int r, int g, int b)
{
	return (0xFFFFFF & (r << 16 | g << 8 | b));
}

int	get_r(const int rgb)
{
	return ((rgb & (0xFF << 16)) >> 16);
}

int	get_g(const int rgb)
{
	return ((rgb & (0xFF << 8)) >> 8);
}

int	get_b(const int rgb)
{
	return (rgb & 0xFF);
}

int	gen_darker_color(int color, int dark)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color) - dark;
	if (r < 0)
		r = 0;
	g = get_g(color) - dark ;
	if (g < 0)
		g = 0;
	b = get_b(color) - dark;
	if (b < 0)
		b = 0;
	color = create_rgb(r, g, b);
	return (color);
}
