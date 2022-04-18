/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:01:29 by achansel          #+#    #+#             */
/*   Updated: 2021/10/22 17:50:45 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (start >= ft_strlen((char *) s))
		return (ft_calloc(1, sizeof(char)));
	if ((start + len > (size_t) ft_strlen((char *) s)))
		return (ft_strdup((char *) &s[start]));
	return (ft_strndup((char *) &s[start], len));
}
