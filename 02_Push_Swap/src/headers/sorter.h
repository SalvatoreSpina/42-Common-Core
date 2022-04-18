/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:17 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:05 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "common.h"

int		tagged(t_list *list, int tag);
void	five_optimized(t_mem *mem);
void	put_tag(t_list *start, t_mem *mem);
int		index_asc_order(t_list *list, t_list *start, int set);
int		find_biggest_asc_order(t_list *start, int set);
void	rotate_both(t_mem *mem, int *rot_a, int *rot_b);
void	rotate(t_mem *mem, int rot_a, int rot_b);
void	initialise_values(t_mem *mem);
int		distance_to_top(t_list *a, int tag);
int		distance_to_tag(int tag, int size);
t_list	*closest_in_group(t_list *list, int cur_group, int group_size);
int		swap_good(t_list *list);
int		insert_distance(t_list *list, int t, int size);
void	calculate_b_rotation(t_mem *m, int max_dist, int *rot_a, int *rot_b);
void	fill_b(t_mem *m);
void	resolve(t_mem *m, int cur_group);

#endif
