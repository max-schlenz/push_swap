/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:48:23 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/30 15:22:51 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	post_run(t_psvars **vars)
{
	if ((*vars)->op_count < (*vars)->op_count_best)
	{
		(*vars)->op_count_best = (*vars)->op_count;
		(*vars)->pvt_best = (*vars)->pvt;
	}
	if ((*vars)->flag_print == 1)
	{
		free(*vars);
		exit (0);
	}
	if (((*vars)->pvt == 20) || (*vars)->pvt == 9)
	{
		(*vars)->pvt = (*vars)->pvt_best;
		(*vars)->flag_print = 1;
	}
	else
		(*vars)->pvt++;
	(*vars)->op_count = 0;
	(*vars)->counter_group = 1;
}

int	main(int argc, char **argv)
{
	t_pslist	*s_a;
	t_pslist	*s_b;
	t_psvars	*vars;

	init_struct(&vars);
	while (1 && argc >= 2)
	{
		ft_intlstclear(&s_a, &s_b);
		populate(argc, argv, &s_a, &s_b);
		dupe_check(&s_a);
		check_sort(&s_a, 1);
		create_index(&s_a, &vars);
		if (vars->index_max < 4)
			sort_small_stack(&s_a, &s_b, &vars);
		else
		{
			pivot_stack(&s_a, &s_b, &vars);
			post_pivot(&s_a, &s_b, &vars);
			sort(&s_a, &s_b, &vars);
		}
		post_run(&vars);
	}
	return (0);
}
