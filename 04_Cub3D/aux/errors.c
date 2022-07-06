/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:03:53 by sspina            #+#    #+#             */
/*   Updated: 2022/06/28 16:21:57 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	They are almost useless (like me), just save some writing cause it's 
	better than writing the printf syntax everytime.
	You can add colors in two functions (red and green), put them before the
	printf, and then after it a third function to reset colors.
	I would've done that but j'ai la flemme (yes good french mamma mia!)
*/

int	error_msg(char *message)
{
	printf("\e[1;31mError: %s\e[m\n", message);
	return (1);
}

int	success_msg(char *message)
{
	printf("\e[1;32m%s\e[m\n", message);
	return (0);
}
