/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:47:01 by achansel          #+#    #+#             */
/*   Updated: 2021/11/17 12:48:14 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnjoin(char *dest, char *src, unsigned int nb)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(ft_strlen(dest) + nb + 1);
	while (dest[i])
	{
		new[i] = dest[i];
		i++;
	}
	while (src[j] && nb--)
	{
		new[i + j] = src[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
