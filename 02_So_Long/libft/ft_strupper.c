/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:42:39 by sspina            #+#    #+#             */
/*   Updated: 2021/11/18 14:42:40 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_toupper((int) str[i]) != (int) str[i])
			str[i] = (char) ft_toupper((int) str[i]);
		i++;
	}
	return (str);
}
