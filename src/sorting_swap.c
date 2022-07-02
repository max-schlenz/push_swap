/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:53:37 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/29 12:08:33 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_output(size_t flag, t_psvars **vars)
{
	(*vars)->op_count++;
	if ((*vars)->flag_print)
	{
		if (flag == 0)
			write(1, "sa\n", 3);
		if (flag == 1)
			write(1, "sb\n", 3);
		if (flag == 2)
			write(1, "ss\n", 3);
	}
}

void	swap(t_pslist **s_a, t_pslist **s_b, size_t flag, t_psvars **vars)
{
	t_pslist	*tmp_elem;

	if (flag == 0 || flag == 2)
	{
		tmp_elem = ft_intlstnew((*s_a)->content, (*s_a)->index);
		(*s_a)->index = (*s_a)->next->index;
		(*s_a)->content = (*s_a)->next->content;
		(*s_a)->next->index = tmp_elem->index;
		(*s_a)->next->content = tmp_elem->content;
		free(tmp_elem);
	}
	else if (flag == 1 || flag == 2)
	{
		tmp_elem = ft_intlstnew((*s_b)->content, (*s_b)->index);
		(*s_b)->index = (*s_b)->next->index;
		(*s_b)->content = (*s_b)->next->content;
		(*s_b)->next->index = tmp_elem->index;
		(*s_b)->next->content = tmp_elem->content;
		free(tmp_elem);
	}
	swap_output(flag, vars);
}
