/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:23:56 by sspina            #+#    #+#             */
/*   Updated: 2021/10/27 15:24:53 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sour;

	dest = (char *)dst;
	sour = (char *)src;
	if (dst == src)
		return (dst);
	if (sour < dest)
	{
		while (len--)
			*(dest + len) = *(sour + len);
		return (dst);
	}
	while (len--)
		*dest++ = *sour++;
	return (dst);
}
