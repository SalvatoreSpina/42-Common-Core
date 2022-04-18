/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:57 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:32 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/get_next_line.h"

void	clearfd(t_fd **fdlst, t_fd *target)
{
	t_fd	*tmp;

	if (!fdlst || !(*fdlst))
		return ;
	if (*fdlst == target)
	{
		*fdlst = target->next;
		free(target->content);
		free(target);
		return ;
	}
	tmp = *fdlst;
	while (tmp && (tmp->next != target))
		tmp = tmp->next;
	tmp->next = target->next;
	free(target->content);
	free(target);
}

t_fd	*newfd(int fd)
{
	t_fd	*new;

	new = (t_fd *)malloc(sizeof(t_fd));
	if (!new)
		return (NULL);
	new->value = fd;
	new->content = ft_strndup("", 0);
	new->next = NULL;
	return (new);
}

t_fd	*setfd(t_fd **fdlst, int fd)
{
	t_fd	*target;

	if (!fdlst)
		return (NULL);
	target = *fdlst;
	if (!target)
	{
		target = newfd(fd);
		*fdlst = target;
		return (target);
	}
	while (target && (target->value != fd))
		target = target->next;
	if (target)
		return (target);
	target = newfd(fd);
	target->next = *fdlst;
	*fdlst = target;
	return (target);
}
