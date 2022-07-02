/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:51:27 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/28 15:15:12 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_rest_inplace(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	if ((*s_a)->index == (*vars)->index_max)
		rotate(s_a, 0, vars);
	if ((*s_a)->next->index == (*vars)->index_max)
	{
		if ((*s_a)->index == (*vars)->index_max - 1)
			reverse_rotate(s_a, 0, vars);
		else if ((*s_a)->index == (*vars)->index_max - 2)
		{
			swap(s_a, s_b, 0, vars);
			rotate(s_a, 0, vars);
		}
	}
	if ((*s_a)->index > (*s_a)->next->index)
		swap(s_a, s_b, 0, vars);
}

void	post_pivot(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	while (ft_intlstsize(*s_a) > 3)
	{
		if ((*s_a)->index <= (*vars)->index_max - 3)
		{
			push(s_a, s_b, 0, vars);
			if ((*s_b)->index < ((*vars)->index_max - (*vars)->num_elems_group))
				rotate(s_b, 1, vars);
		}
		else
			rotate(s_a, 0, vars);
	}
	sort_rest_inplace(s_a, s_b, vars);
}

static void	push_bot(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	push(s_a, s_b, 0, vars);
	if ((*s_b)->next && (*s_b)->index > (*vars)->group)
	{	
		if ((*s_a) && (*s_a)->index > (*vars)->group + (*vars)->num_elems_group)
			rotate_ab(s_a, s_b, vars);
		else
			rotate(s_b, 1, vars);
	}
}

void	pivot_stack(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	(*vars)->num_elems_group = ft_intlstsize(*s_a) / (*vars)->pvt;
	while ((*vars)->counter_group < (*vars)->pvt - 1)
	{
		(*vars)->counter_elem = (*vars)->num_elems_group * 2;
		(*vars)->group = (*vars)->num_elems_group * (*vars)->counter_group;
		while ((*vars)->counter_elem > 0 && (*s_a)->index > 0)
		{
			if (((*s_a)->index) <= \
				(((*vars)->group + (*vars)->num_elems_group)))
			{
				if ((*s_a)->index < \
					(*vars)->index_max - (*vars)->num_elems_group)
				{
					if (((*s_a)->index) <= (*vars)->group)
						push(s_a, s_b, 0, vars);
					else
						push_bot(s_a, s_b, vars);
				}
				(*vars)->counter_elem--;
			}
			else
				rotate(s_a, 0, vars);
		}
		(*vars)->counter_group += 2;
	}
}
