/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:28:39 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/30 12:15:28 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_pslist	*index_rest_of_stack(t_pslist *stack, t_psvars **vars)
{
	t_pslist	*temp_stack;
	long		prev_elem;
	size_t		elem_n;
	size_t		i;

	temp_stack = stack;
	prev_elem = (long)INT32_MIN - 1;
	i = 1;
	while (i < (*vars)->index)
	{
		prev_elem = find_next_bigger(&stack, prev_elem);
		i++;
	}
	elem_n = find_next_bigger_pos(&stack, prev_elem);
	while (elem_n > 1)
	{
		temp_stack = temp_stack->next;
		elem_n--;
	}
	temp_stack->index = (*vars)->index;
	return (stack);
}

static t_pslist	*index_stack_smallest(t_pslist *stack)
{
	t_pslist	*temp_stack;
	size_t		elem_n;

	temp_stack = stack;
	elem_n = find_smallest_pos(&stack);
	while (elem_n > 1)
	{
		temp_stack = temp_stack->next;
		elem_n--;
	}
	temp_stack->index = 1;
	return (stack);
}

void	create_index(t_pslist **s_a, t_psvars **vars)
{
	(*vars)->index = 1;
	(*vars)->index_max = ft_intlstsize(*s_a);
	*s_a = index_stack_smallest(*s_a);
	while ((*vars)->index <= (*vars)->index_max)
	{
		*s_a = index_rest_of_stack(*s_a, vars);
		(*vars)->index++;
	}
	if ((*vars)->pvt == 0 && (*vars)->flag_print == 0)
	{
		if ((*vars)->index_max <= 12)
			(*vars)->pvt = 2;
		else if ((*vars)->index_max <= 100)
			(*vars)->pvt = 4;
		else
			(*vars)->pvt = 12;
	}
}
