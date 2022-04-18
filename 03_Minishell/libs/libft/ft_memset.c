/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:21:06 by achansel          #+#    #+#             */
/*   Updated: 2021/10/19 16:06:37 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dstp;
	size_t			i;

	i = 0;
	dstp = (unsigned char *) b;
	while (i < len)
		dstp[i++] = (unsigned char) c;
	return (b);
}
