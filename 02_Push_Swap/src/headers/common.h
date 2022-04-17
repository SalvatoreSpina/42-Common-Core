/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:13 by sspina            #+#    #+#             */
/*   Updated: 2022/01/03 17:38:15 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				keep;
	struct s_list	*next;
	struct s_list	*next_sort;
}					t_list;

typedef struct s_mem
{
	t_list			*a;
	t_list			*b;
	int				max;
	int				big;
	int				size;
	int				group_number;
	int				group_size;
	int				print;
	t_list			*temp;
	int				action_count;
}					t_mem;

void	swap_a(t_mem *mem);
void	swap_b(t_mem *mem);
void	swap_a_b(t_mem *mem);
void	push_a(t_mem *mem);
void	push_b(t_mem *mem);
void	rev_rotate_a(t_mem *mem);
void	rev_rotate_b(t_mem *mem);
void	rev_rotate_a_b(t_mem *mem);
void	rotate_a(t_mem *mem);
void	rotate_b(t_mem *mem);
void	rotate_a_b(t_mem *mem);
int		ft_isdigit(int c);
int		ft_atoi(char *str, t_mem *mem);
int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_strcmp(const char *s1, const char *s2);
void	lists_swap(t_list **previous_next, t_list *last);
void	dirt_sorting(t_list **begin_list);
void	ft_putstr(char *str);
void	ft_puterr(char *str);
void	free_list(t_list **list);
int		list_size(t_list *l);
t_list	*get_last(t_list *l);
int		list_contains_value(t_list *l, int value);
int		is_ordered(t_mem *m);
void	arg_checking(int argc, char **argv, t_mem *mem);
void	no_leaks_please(t_mem *mem);
void	exit_error(t_mem *mem);
void	fill_a(t_list **stack, int value, int tag, t_mem *mem);
void	swap(t_list **stack);
void	push_top(t_list **x1, t_list **x2);
void	push_top_to_bot(t_list **x);
void	push_bot_to_top(t_list **x);

#endif
