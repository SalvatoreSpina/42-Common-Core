/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:35:24 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:03 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	c;
	unsigned char	*t;

	c = 0;
	t = (unsigned char *)s;
	while (n > c)
	{
		t[c] = 0;
		c++;
	}
}
