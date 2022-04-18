/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:34:54 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 18:33:28 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_putstr_fd(char *s, int fd);
int				fsf(char *s, ...);
char			**ft_split(const char *str, char delim);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strndup(char *str, int n);
char			*ft_strnstr(const char *hs, const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
t_list			*ft_lstfind(t_list *l, int (*c)(void *, void *), void *r);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
t_list			*ft_lstdelone_ptr(t_list **h, t_list *n, void (*d)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *ls, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

typedef struct s_gnl_fdbuff
{
	int					fd;
	char				*buf;
	struct s_gnl_fdbuff	*prev;
	struct s_gnl_fdbuff	*next;
}	t_fdbuf_lst;

char			*ft_strnjoin(char *dest, char *src, unsigned int nb);
char			*get_next_line(int fd);

#endif
