/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:44:02 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:26 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_put_hex(unsigned long long p, int u)
{
	if (p == 0)
		return (ft_putstr("0"));
	if (u == 1)
		return (ft_dec_to_hex(p, 0, 1));
	return (ft_dec_to_hex(p, 1, 1));
}
