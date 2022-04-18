/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:27:40 by achansel          #+#    #+#             */
/*   Updated: 2021/10/23 13:29:23 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	retsize;

	i = ft_strlen(dst);
	retsize = i;
	if (i > dstsize)
		retsize = dstsize;
	if (retsize == dstsize)
		return (i + ft_strlen((char *) src));
	j = 0;
	while (src[j] && i + j < dstsize - 1 && dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dstsize && i <= dstsize)
		dst[i + j] = '\0';
	return (retsize + ft_strlen((char *) src));
}
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	i;

	i = 0;
	c = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen((char *) src));
	while (src[i] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[i];
		i++;
		c++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen((char *) &src[i]));
}
