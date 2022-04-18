/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:20 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:45 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_hex(va_list *args, int c)
{
	unsigned int	hex;
	int				cnt;

	cnt = 0;
	hex = (unsigned int)va_arg(*args, unsigned int);
	if (c == 'x')
		cnt += ft_putnbr_base(hex, "0123456789abcdef");
	if (c == 'X')
		cnt += ft_putnbr_base(hex, "0123456789ABCDEF");
	return (cnt);
}
