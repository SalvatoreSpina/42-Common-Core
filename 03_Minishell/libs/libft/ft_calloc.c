/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:23:15 by achansel          #+#    #+#             */
/*   Updated: 2021/10/19 11:32:58 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		len;

	len = count * size;
	ptr = malloc(len);
	if (ptr)
	{
		ft_bzero(ptr, len);
		return (ptr);
	}
	return (NULL);
}
