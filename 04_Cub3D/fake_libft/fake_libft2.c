/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_libft2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:16:02 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:04:34 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	strcopy(char *dst, const char *src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	theres_a_digit(char *str)
{
	while (str && *str)
	{
		if (ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

int	check_only_digits(char *str)
{
	while (str && *str)
	{
		if (!(ft_isdigit(*str)) && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}
