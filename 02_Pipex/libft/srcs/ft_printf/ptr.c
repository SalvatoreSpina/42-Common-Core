/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:27 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:45 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_ptr(va_list *args)
{
	size_t	addr;
	int		cnt;

	cnt = 0;
	cnt += write(1, "0x", 2);
	addr = (size_t)va_arg(*args, void *);
	cnt += ft_putnbr_base(addr, "0123456789abcdef");
	return (cnt);
}
