/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:41:12 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:26 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	t;
	size_t	j;
	size_t	i;
	size_t	s;

	t = ft_strlen((const char *)dst);
	j = t;
	i = 0;
	s = ft_strlen(src);
	while ((t < dstsize) && (src[i] != '\0') && (j < dstsize - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (dstsize != 0 && (t < dstsize))
		dst[j] = '\0';
	if (t > dstsize)
		return (dstsize + s);
	return (t + s);
}
