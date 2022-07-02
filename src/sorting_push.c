/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:36:19 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/28 16:22:24 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	free_stack(t_pslist **stack)
{
	t_pslist	*tmp;

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}

void	push(t_pslist **s_a, t_pslist **s_b, size_t flag, t_psvars **vars)
{
	if (flag == 1 && (*s_b))
	{
		if (!(*s_a))
			*s_a = ft_intlstnew((*s_b)->content, (*s_b)->index);
		else
			ft_intlstadd_front(s_a, ft_intlstnew((*s_b)->content, \
												(*s_b)->index));
		if ((*s_b)->next)
			free_stack(s_b);
		if ((*vars)->flag_print)
			write(1, "pa\n", 3);
	}
	else if ((*s_a))
	{
		if (!(*s_b))
			*s_b = ft_intlstnew((*s_a)->content, (*s_a)->index);
		else
			ft_intlstadd_front(s_b, ft_intlstnew((*s_a)->content, \
													(*s_a)->index));
		if ((*s_a)->next)
			free_stack(s_a);
		if ((*vars)->flag_print)
			write(1, "pb\n", 3);
	}
	(*vars)->op_count++;
}
