/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:41 by sspina            #+#    #+#             */
/*   Updated: 2021/11/30 15:46:43 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fd(int fd)
{
	if (close(fd) == -1)
		exit(error_general("close"));
}

void	close_util(int fd[2])
{
	close_fd(fd[0]);
	close_fd(fd[1]);
}

void	dup2_ok(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit(error_general("dup2"));
}

void	free_point(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	free_ppoint(char ***ptr)
{
	free(**ptr);
	**ptr = NULL;
}
