/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlastchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:35:46 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:03 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_getlastchar(char *str)
{
	return (str[ft_strlen(str) - 1]);
}
