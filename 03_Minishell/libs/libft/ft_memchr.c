/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:12:58 by achansel          #+#    #+#             */
/*   Updated: 2021/10/18 16:18:46 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*scpy;

	i = 0;
	scpy = (unsigned char *) s;
	while (i < n)
	{
		if (scpy[i] == (unsigned char) c)
			return ((void *) &scpy[i]);
		i++;
	}
	return (NULL);
}
