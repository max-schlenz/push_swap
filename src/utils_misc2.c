/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:10:07 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/30 15:22:48 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_struct(t_psvars **vars)
{
	*vars = malloc(sizeof(t_psvars));
	(*vars)->group = 0;
	(*vars)->counter_group = 1;
	(*vars)->counter_elem = 0;
	(*vars)->num_elem = 0;
	(*vars)->num_elems_group = 0;
	(*vars)->index = 0;
	(*vars)->index_max = 0;
	(*vars)->pvt = 0;
	(*vars)->pvt_best = 0;
	(*vars)->flag_print = 0;
	(*vars)->op_count = 0;
	(*vars)->op_count_best = SIZE_MAX;
}

long	find_next_bigger(t_pslist **stack, long num)
{
	t_pslist	*tmp_stack;
	long		tmp_elem;
	int			i;

	i = 1;
	tmp_stack = *stack;
	tmp_elem = tmp_stack->content;
	while (tmp_stack)
	{
		if (tmp_stack->content > num && \
			(tmp_stack->content < tmp_elem || i == 1))
		{
			tmp_elem = tmp_stack->content;
			i = 0;
		}
		tmp_stack = tmp_stack->next;
	}
	if (tmp_elem < num)
		return (0);
	return (tmp_elem);
}

size_t	find_next_bigger_pos(t_pslist **stack, long num)
{
	t_pslist	*tmp_stack;
	long		tmp_elem;
	int			i;

	i = 1;
	tmp_stack = *stack;
	tmp_elem = tmp_stack->content;
	while (tmp_stack)
	{
		if (tmp_stack->content > num && \
			(tmp_stack->content < tmp_elem || i == 1))
		{
			tmp_elem = tmp_stack->content;
			i = 0;
		}
		tmp_stack = tmp_stack->next;
	}
	if (tmp_elem < num)
		return (0);
	return (find_elem_in_stack(stack, tmp_elem));
}

size_t	check_sort(t_pslist **stack, size_t flag)
{
	t_pslist	*tmp_stack;

	tmp_stack = *stack;
	while (tmp_stack->next)
	{
		if (tmp_stack->content > tmp_stack->next->content)
			return (1);
		tmp_stack = tmp_stack->next;
	}
	if (flag)
		exit (1);
	return (0);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}
