/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:43:04 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:37 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	total_length;

	total_length = 0;
	if (format == 'c')
		total_length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		total_length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		total_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i' )
		total_length += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		total_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		total_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		total_length += ft_print_percent();
	return (total_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		total_length;

	i = 0;
	total_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			total_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			total_length += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (total_length);
}
