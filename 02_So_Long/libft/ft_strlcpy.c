/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:41:20 by sspina            #+#    #+#             */
/*   Updated: 2021/11/18 14:41:21 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	l;

	if (dst == 0 || src == 0)
		return (0);
	l = 0;
	c = 0;
	while (src[l] != '\0')
		l++;
	while (src[c] && c < (dstsize - 1))
	{
		if (dstsize == 0)
			return (l);
		dst[c] = src[c];
		c++;
	}
	if (dstsize != 0)
		dst[(c)] = '\0';
	return (l);
}
