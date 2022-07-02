/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:39:38 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/30 12:25:55 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_small_stack(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{	
	while (check_sort(s_a, 0))
	{
		if ((*s_a)->index == (*vars)->index_max)
			rotate(s_a, 0, vars);
		else if (ft_intlstlast(*s_a)->index == 1)
			reverse_rotate(s_a, 0, vars);
		else if ((*s_a)->next && (*s_a)->index > (*s_a)->next->index)
			swap(s_a, s_b, 0, vars);
		else if ((*s_a)->next && (*s_a)->index < (*s_a)->next->index && \
					(*s_a)->next->index > ft_intlstlast(*s_a)->index)
		{
			swap(s_a, s_b, 0, vars);
			rotate(s_a, 0, vars);
		}
	}
}
