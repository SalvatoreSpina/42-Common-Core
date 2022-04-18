/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:38:12 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:05 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		write_char(va_list *args);
int		write_str(va_list *args);
int		write_int(va_list *args);
int		write_uint(va_list *args);
int		write_ptr(va_list *args);
int		write_hex(va_list *args, int c);

#endif
