/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:24:46 by achansel          #+#    #+#             */
/*   Updated: 2021/10/19 11:12:25 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstp;
	const unsigned char	*srcp;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	dstp = (unsigned char *) dst;
	srcp = (const unsigned char *) src;
	while (i < n)
	{
		dstp[i] = srcp[i];
		i++;
	}
	return (dst);
}
