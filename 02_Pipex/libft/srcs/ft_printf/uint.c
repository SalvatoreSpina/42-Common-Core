/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:37 by sspina            #+#    #+#             */
/*   Updated: 2021/11/30 15:40:38 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_uint(va_list *args)
{
	char			*num;
	unsigned int	tmp;
	int				cnt;

	tmp = va_arg(*args, unsigned int);
	num = ft_uitoa(tmp);
	if (!num)
		return (0);
	cnt = write(1, num, ft_strlen(num));
	free(num);
	return (cnt);
}
