/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:44:00 by achansel          #+#    #+#             */
/*   Updated: 2021/10/23 14:14:47 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*retval;
	char	*cpy;

	cpy = (char *) s;
	retval = NULL;
	while (*cpy)
	{
		if (*cpy == (char) c)
			retval = cpy;
		cpy++;
	}
	if (c == '\0')
		return (cpy);
	return (retval);
}
