/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:26:33 by sspina            #+#    #+#             */
/*   Updated: 2021/10/27 15:37:40 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;

	len = ft_strlen(s1) + 1;
	dup = malloc((len) * sizeof(char));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s1, len);
	return (dup);
}
