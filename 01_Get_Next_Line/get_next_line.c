/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:02:09 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:59 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string_buffer = NULL ;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!string_buffer)
		string_buffer = ft_strdup("");
	if (read_file(fd, &buffer, &string_buffer, &line) == 0 && *line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}

int	read_file(int fd, char **buffer, char **string_buff, char **line)
{
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	while (!ft_strchr(*string_buff, '\n') && read_bytes)
	{
		read_bytes = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[read_bytes] = '\0';
		temp = *string_buff;
		*string_buff = ft_strjoin(*string_buff, *buffer);
		free_ptr(temp);
	}
	free_ptr(*buffer);
	get_line(line, string_buff);
	return (read_bytes);
}

char	*get_line(char **line, char **string_buff)
{
	char	*temp;
	int		buff_newl;

	buff_newl = 0;
	temp = *string_buff;
	while ((*string_buff)[buff_newl] != '\n' &&
		(*string_buff)[buff_newl] != '\0')
		buff_newl++;
	if (ft_strchr(*string_buff, '\n'))
	{
		*line = ft_substr(*string_buff, 0, buff_newl + 1);
		*string_buff = ft_strdup(*string_buff + buff_newl + 1);
	}
	else
	{
		*line = ft_strdup(temp);
		*string_buff = NULL;
	}
	free_ptr(temp);
	return (*line);
}
