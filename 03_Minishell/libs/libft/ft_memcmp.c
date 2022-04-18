/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:06:48 by achansel          #+#    #+#             */
/*   Updated: 2021/10/18 16:10:04 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1c;
	const unsigned char	*s2c;

	s1c = s1;
	s2c = s2;
	if (!n)
		return (0);
	while (*s1c == *s2c && --n)
	{
		s2c++;
		s1c++;
	}
	return (*s1c - *s2c);
}
