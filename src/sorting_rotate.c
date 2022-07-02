/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:53:37 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/30 14:08:42 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate(t_pslist **stack, size_t flag, t_psvars **vars)
{
	t_pslist	*tmp;
	t_pslist	*last;

	if ((*stack)->next)
	{	
		last = ft_intlstlast(*stack);
		tmp = *stack;
		ft_intlstadd_front(stack, ft_intlstlast(*stack));
		while (tmp->next != last)
				tmp = tmp->next;
		tmp->next = NULL;
		free(tmp->next);
		if (flag == 0 && (*vars)->flag_print)
			write(1, "rra\n", 4);
		else if (flag == 1 && ((*vars)->flag_print))
			write(1, "rrb\n", 4);
		if (flag < 2)
			(*vars)->op_count++;
	}	
}

void	reverse_rotate_ab(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	if (*s_a)
		reverse_rotate(s_a, 2, vars);
	if (*s_b)
		reverse_rotate(s_b, 2, vars);
	if ((*vars)->flag_print)
		write(1, "rrr\n", 4);
	(*vars)->op_count++;
}

void	rotate_ab(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	if (*s_a)
		rotate(s_a, 2, vars);
	if (*s_b)
		rotate(s_b, 2, vars);
	if ((*vars)->flag_print)
		write(1, "rr\n", 3);
	(*vars)->op_count++;
}

void	rotate(t_pslist **stack, size_t flag, t_psvars **vars)
{
	t_pslist	*tmp;

	if ((*stack)->next)
	{
		ft_intlstadd_back(stack, \
			ft_intlstnew((*stack)->content, (*stack)->index));
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
		if (flag == 0 && (*vars)->flag_print)
			write(1, "ra\n", 3);
		else if (flag == 1 && ((*vars)->flag_print))
			write(1, "rb\n", 3);
		if (flag < 2)
			(*vars)->op_count++;
	}
}
