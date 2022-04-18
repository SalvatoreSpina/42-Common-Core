/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:27:51 by achansel          #+#    #+#             */
/*   Updated: 2021/10/22 14:46:16 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	int				length;

	i = 0;
	length = ft_strlen((char *) s);
	while (i < (unsigned int) length)
	{
		f(i, &s[i]);
		i++;
	}
}
