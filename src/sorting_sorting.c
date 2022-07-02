/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:58:47 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/28 16:19:32 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_second_last(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	push(s_a, s_b, 1, vars);
	if ((*s_a)->next && (*s_a)->index > (*s_a)->next->index)
		swap(s_a, s_b, 0, vars);
	if ((*s_a)->index == (*vars)->num_elem - 1)
	{
		while ((*s_b)->index != (*vars)->num_elem)
		{
			if (get_path_to_elem(s_b, (*vars)->num_elem) == 1)
				rotate(s_b, 1, vars);
			else
				reverse_rotate(s_b, 1, vars);
		}
		push(s_a, s_b, 1, vars);
		(*vars)->num_elem--;
		swap(s_a, s_b, 0, vars);
	}
	(*vars)->num_elem--;
}

static void	sort_third_last(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	int	i;

	push(s_a, s_b, 1, vars);
	(*vars)->num_elem--;
	if (get_path_to_elem(s_b, ((*s_a)->index) + 2))
		rotate_ab(s_a, s_b, vars);
	else
		rotate(s_a, 0, vars);
	i = 2;
	while (i > 0)
	{
		while ((*s_b)->index != ((ft_intlstlast(*s_a)->index) + i))
		{
			if (get_path_to_elem(s_b, (ft_intlstlast(*s_a)->index) + i))
				rotate(s_b, 1, vars);
			else
				reverse_rotate(s_b, 1, vars);
		}
		push(s_a, s_b, 1, vars);
		(*vars)->num_elem--;
		i--;
	}
}

static void	rrot_smallest(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	if ((*s_b)->index < (*vars)->num_elem)
		reverse_rotate_ab(s_a, s_b, vars);
	else
		reverse_rotate(s_a, 0, vars);
}

static void	rrot_to_next(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	if ((*s_a)->next && (*s_a)->index == (ft_intlstlast(*s_a)->index + 1))
		reverse_rotate_ab(s_a, s_b, vars);
	else
		reverse_rotate(s_b, 1, vars);
}

void	sort(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	(*vars)->num_elem = ft_intlstsize(*s_b);
	while ((*vars)->num_elem > 0)
	{
		if ((*s_a)->next && (*s_a)->index == (ft_intlstlast(*s_a)->index + 1))
			rrot_smallest(s_a, s_b, vars);
		else if ((*s_b)->index >= (*vars)->num_elem - 1)
			sort_second_last(s_a, s_b, vars);
		else if ((*s_b)->index == (*vars)->num_elem - 2)
			sort_third_last(s_a, s_b, vars);
		if (get_path_to_elem(s_b, (*vars)->num_elem))
			rotate(s_b, 1, vars);
		else
			rrot_to_next(s_a, s_b, vars);
	}
	if (ft_intlstlast(*s_a)->index < (*s_a)->index)
		reverse_rotate(s_a, 0, vars);
}
