/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:38:53 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:19 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_fd(void *p)
{
	int		l;

	l = 0;
	if (!p)
		return (ft_putstr("0x0"));
	l += ft_putstr("0x");
	l += ft_dec_to_hex((unsigned long long) p, 1, 1);
	return (l);
}
