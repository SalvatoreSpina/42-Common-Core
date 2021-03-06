/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:23:46 by sspina            #+#    #+#             */
/*   Updated: 2021/10/27 15:23:08 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstchar;
	const char	*srcchar;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dstchar = (char *)dst;
	srcchar = (const char *)src;
	while (n--)
		dstchar[n] = srcchar[n];
	return (dst);
}
