/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:01:47 by achansel          #+#    #+#             */
/*   Updated: 2021/11/22 15:28:21 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/* This function returns the concat of the previous read with the actual read, 
 * if the old read was just a null-byte, it duplicates the new read.
 * Before returning, it always frees the old_read buf */
static char	*concat_reads(char *old_buf, char *new_buf, int rd_size)
{
	char	*lol;

	if (old_buf && ft_strlen(old_buf))
	{
		lol = ft_strnjoin(old_buf, new_buf, rd_size);
		free(old_buf);
		return (lol);
	}
	if (old_buf && !ft_strlen(old_buf))
		free(old_buf);
	return (ft_strndup(new_buf, rd_size));
}

/* This function, as its name implies, returns a node from a doubly linked list
 * where node->fd == fd, if the node couldn't be found, the function creates 
 * and then returns the newly created node */
static t_fdbuf_lst	*get_or_create_node_by_fd(t_fdbuf_lst **headp, int fd)
{
	t_fdbuf_lst			*curr;
	t_fdbuf_lst			*new;

	curr = *headp;
	if (curr)
	{
		while (curr->next)
		{
			if (curr->fd == fd)
				return (curr);
			curr = curr->next;
		}
		if (curr->fd == fd)
			return (curr);
	}
	new = malloc(sizeof(t_fdbuf_lst));
	new->next = NULL;
	new->prev = curr;
	new->fd = fd;
	new->buf = NULL;
	if (*headp == NULL)
		*headp = new;
	else
		new->prev->next = new;
	return (new);
}

/* This function is called when we're done reading the file or when we couldn't
 * read from it, when returning what was read.
 * It finds the right node for fd, duplicates and return the buffer if
 * strlen(node->buf) > 0. After this has been done, it connects the previous 
 * and next node together and it frees the node corresponding to the fd. */
static char	*free_by_fd(t_fdbuf_lst **headp, int fd)
{
	char		*current_fd_buf;
	t_fdbuf_lst	*curr;

	current_fd_buf = NULL;
	curr = get_or_create_node_by_fd(headp, fd);
	if (curr->buf)
	{
		if (ft_strlen(curr->buf))
			current_fd_buf = ft_strdup(curr->buf);
		free(curr->buf);
	}
	if (curr == *headp)
	{
		*headp = curr->next;
		if (curr->next)
			curr->next->prev = NULL;
	}
	else
	{
		curr->prev->next = curr->next;
		if (curr->next)
			curr->next->prev = curr->prev;
	}
	free(curr);
	return (current_fd_buf);
}

/* This function cuts the buf before and after the line break,
 * Without freeing the old buf */
static void	split_at_nl(char **cut_line, char **after_line_break, char *buf)
{
	int	idx;

	idx = 0;
	while (buf[idx] && buf[idx] != '\n')
		idx++;
	*after_line_break = ft_strdup(&buf[idx + 1]);
	*cut_line = ft_strndup(buf, idx + 1);
}

char	*get_next_line(int fd)
{
	static t_fdbuf_lst	*fdbufs;
	char				**buf_by_fd;
	char				*processed_lines[2];
	char				*buffer;
	int					rd_size;

	rd_size = BUFFER_SIZE;
	buffer = malloc(BUFFER_SIZE + 1);
	buf_by_fd = &(get_or_create_node_by_fd(&fdbufs, fd)->buf);
	while (!ft_strchr(*buf_by_fd, '\n') && (rd_size == BUFFER_SIZE))
	{
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size > 0)
			*buf_by_fd = concat_reads(*buf_by_fd, buffer, rd_size);
	}
	free(buffer);
	if (!*buf_by_fd)
		return (free_by_fd(&fdbufs, fd));
	else if (ft_strchr(*buf_by_fd, '\n'))
		split_at_nl(&processed_lines[0], &processed_lines[1], *buf_by_fd);
	else
		return (free_by_fd(&fdbufs, fd));
	free(*buf_by_fd);
	*buf_by_fd = processed_lines[1];
	return (processed_lines[0]);
}
