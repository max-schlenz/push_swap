/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:54:41 by mschlenz          #+#    #+#             */
/*   Updated: 2022/07/01 16:55:46 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	dupe_check(t_pslist **stack)
{
	t_pslist	*tmp_stack;
	t_pslist	*tmp_stack2;

	tmp_stack = *stack;
	tmp_stack = tmp_stack->next;
	tmp_stack2 = *stack;
	while (tmp_stack2->next)
	{
		while (tmp_stack)
		{
			if (tmp_stack2->content == tmp_stack->content)
				error();
			tmp_stack = tmp_stack->next;
		}
		tmp_stack2 = tmp_stack2->next;
		tmp_stack = tmp_stack2->next;
	}
	return (1);
}

void	populate(int argc, char **argv, t_pslist **s_a, t_pslist **s_b)
{
	int		i;
	int		j;
	char	**elem;

	i = 1;
	j = 1;
	*s_b = NULL;
	while (i < argc)
	{
		elem = ft_split(argv[i], ' ');
		if (j == 1)
		{
			*s_a = ft_intlstnew(ft_ps_atoi(elem[0]), 0);
			free(elem[0]);
		}
		while (elem[j])
		{
			ft_intlstadd_back(s_a, ft_intlstnew(ft_ps_atoi(elem[j]), 0));
			free(elem[j]);
			j++;
		}
		j = 0;
		i++;
		free(elem);
	}	
}
