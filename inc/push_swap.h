/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:46:26 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/30 14:08:06 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_pslist
{
	long				content;
	size_t				index;
	struct s_pslist		*next;
}						t_pslist;

typedef struct s_psvars
{
	size_t			group;
	int				counter_group;
	int				counter_elem;
	size_t			num_elem;
	size_t			num_elems_group;
	size_t			index;
	size_t			index_max;
	int				pvt;
	int				pvt_best;
	size_t			op_count;
	size_t			op_count_best;
	size_t			flag_print;
}					t_psvars;

t_pslist	*ft_intlstnew(long content, size_t index);
t_pslist	*ft_intlstlast(t_pslist *lst);
void		ft_intlstadd_front(t_pslist **lst, t_pslist *new);
void		ft_intlstadd_back(t_pslist **lst, t_pslist *new);
size_t		ft_intlstsize(t_pslist *lst);
void		ft_intlstclear(t_pslist **s_a, t_pslist **s_b);
void		ft_intlstdelone(t_pslist *lst);

long		ft_ps_atoi(const char *str);

void		init_struct(t_psvars **vars);
void		error(void);
size_t		dupe_check(t_pslist **stack);
void		populate1arg(char **argv, t_pslist **s_a, t_pslist **s_b);
void		populate(int argc, char **argv, t_pslist **s_a, t_pslist **s_b);
size_t		parse_args(int argc, char **argv);
size_t		check_sort(t_pslist **stack, size_t flag);
void		create_index(t_pslist **s_a, t_psvars **vars);
void		sort_small_stack(t_pslist **s_a, t_pslist **s_b, t_psvars **vars);

void		pivot_stack(t_pslist **s_a, t_pslist **s_b, t_psvars **vars);
void		post_pivot(t_pslist **s_a, t_pslist **s_b, t_psvars **vars);
void		sort(t_pslist **s_a, t_pslist **s_b, t_psvars **vars);

void		swap(t_pslist **s_a, t_pslist **s_b, size_t flag, t_psvars **vars);
void		rotate(t_pslist **stack, size_t flag, t_psvars **vars);
void		rotate_ab(t_pslist **s_a, t_pslist **s_b, t_psvars **vars);
void		reverse_rotate(t_pslist **stack, size_t flag, t_psvars **vars);
void		reverse_rotate_ab(t_pslist **s_a, t_pslist **s_b, t_psvars **vars);
void		push(t_pslist **s_a, t_pslist **s_b, size_t flag, t_psvars **vars);

size_t		find_elem_in_stack(t_pslist **stack, long num);
long		find_next_bigger(t_pslist **stack, long num);
size_t		find_next_bigger_pos(t_pslist **stack, long num);
size_t		find_smallest_pos(t_pslist **stack);
size_t		get_shortest_path(t_pslist **stack, size_t start, size_t end);
size_t		get_path_to_elem(t_pslist **stack, size_t index);
size_t		find_elem_index_in_stack(t_pslist **stack, size_t index);

#endif