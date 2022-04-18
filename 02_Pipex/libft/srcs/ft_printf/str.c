/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:33 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:45 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_str(va_list *args)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	cnt = write(1, str, ft_strlen(str));
	return (cnt);
}
