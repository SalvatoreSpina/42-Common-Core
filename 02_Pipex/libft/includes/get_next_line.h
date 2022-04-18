/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:38:17 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:37 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef enum e_gnl
{
	GNLSUC = 1,
	GNLEOF = 0,
	GNLERR = -1,
}	t_gnl;

typedef struct s_fd
{
	int				value;
	char			*content;
	struct s_fd		*next;
}	t_fd;

char	*get_next_line(int fd);
int		get_next_line_beta(int fd, char **line);
t_fd	*newfd(int fd);
t_fd	*setfd(t_fd **fdlst, int fd);
void	clearfd(t_fd **fdlst, t_fd *target);

#endif
