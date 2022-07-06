/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_libft3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:18:33 by sspina            #+#    #+#             */
/*   Updated: 2022/06/28 15:37:39 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../cub3d.h"

int	first_index(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

int	last_index(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != c)
		i--;
	return (i);
}

static char	*joiner(char *s1, char *s2)
{
	int		line_len;
	char	*joined;

	if (!s2)
		return (s1);
	if (s1)
		line_len = ft_strlen(s1);
	else
		line_len = 0;
	joined = malloc(ft_strlen(s2) + line_len + 1);
	if (!joined)
		return (NULL);
	strcopy(joined, s1);
	strcopy(joined + line_len, s2);
	free(s1);
	return (joined);
}

int	read_everything(int fd, char **line)
{
	int			ret;
	static char	buf[INT_MAX];

	if (fd < 0 || fd > 1024 || !line)
		return (-1);
	*line = 0;
	ret = 1;
	while (ret > 0)
	{
		*line = joiner(*line, buf);
		ret = read(fd, buf, INT_MAX);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
	}
	return (0);
}

char	*line_creator(char *str, char *needle)
{
	char	*line;
	char	*trimmedline;
	int		index;

	line = ft_strstr(str, needle);
	if (line)
	{
		line += ft_strlen(needle);
		while (*line == ' ')
			line++;
		index = first_index(line, '\n');
		line = ft_substr(line, 0, index);
		trimmedline = ft_strtrim(line, " ");
		free(line);
		return (trimmedline);
	}
	return (NULL);
}
