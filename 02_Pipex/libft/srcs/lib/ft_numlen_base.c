/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:44:21 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:45 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(int64_t n, uint64_t base)
{
	size_t	len;

	if (base < 2)
		return (0);
	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
