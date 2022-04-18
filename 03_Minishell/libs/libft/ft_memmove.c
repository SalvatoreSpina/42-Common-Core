/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:24:46 by achansel          #+#    #+#             */
/*   Updated: 2021/10/19 19:54:07 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstp;
	const unsigned char	*srcp;
	size_t				i;
	int					dir;

	if ((dst == NULL && src == NULL) || src == dst)
		return (dst);
	dstp = (unsigned char *) dst;
	srcp = (const unsigned char *) src;
	if (dstp > srcp)
	{
		dir = -1;
		i = len - 1;
	}
	else if (dstp < srcp)
	{
		dir = 1;
		i = 0;
	}
	while (len--)
	{
		dstp[i] = srcp[i];
		i += dir;
	}
	return (dst);
}
