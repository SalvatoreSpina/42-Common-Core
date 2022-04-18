/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:41:54 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:15 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				f;

	i = 0;
	f = 0;
	while (f == 0 && (i < n) && (n != 0))
	{
		if ((unsigned char) s1[i] == '\0'
			&& (unsigned char) s2[i] == '\0')
			return (f);
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			f = 1;
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
			f = -1;
		i++;
	}
	return (f);
}
