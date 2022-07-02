/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:03:28 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/30 15:06:31 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	check_sort_chk(t_pslist **s_a, size_t flag)
{
	t_pslist	*stack;

	stack = *s_a;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			if (flag == 0)
				write(1, "KO\n", 3);
			return ;
		}
		stack = stack->next;
	}
	write(1, "OK\n", 3);
	if (flag == 1)
		exit (0);
	else
		return ;
}

static void	populate_chk(int argc, char **argv, t_pslist **s_a, t_pslist **s_b)
{
	int	i;

	if (argc < 2)
		exit (0);
	i = 2;
	ft_intlstclear(s_a, s_b);
	*s_a = NULL;
	*s_b = NULL;
	*s_a = ft_intlstnew(ft_ps_atoi(argv[1]), 0);
	while (i < argc)
	{
		ft_intlstadd_back(s_a, ft_intlstnew(ft_ps_atoi(argv[i]), 0));
		i++;
	}
	if (dupe_check(s_a))
	{
		check_sort_chk(s_a, 1);
		return ;
	}
	error();
	return ;
}

static void	do_op(t_pslist **s_a, t_pslist **s_b, char *op, t_psvars **vars)
{
	if (!ft_strncmp(op, "sa\n", 3))
		swap(s_a, s_b, 0, vars);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap(s_a, s_b, 1, vars);
	else if (!ft_strncmp(op, "ss\n", 3))
		swap(s_a, s_b, 2, vars);
	else if (!ft_strncmp(op, "pb\n", 3))
		push(s_a, s_b, 0, vars);
	else if (!ft_strncmp(op, "pa\n", 3))
		push(s_a, s_b, 1, vars);
	else if (!ft_strncmp(op, "ra\n", 3))
		rotate(s_a, 0, vars);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate(s_b, 1, vars);
	else if (!ft_strncmp(op, "rr\n", 3))
		rotate_ab(s_a, s_b, vars);
	else if (!ft_strncmp(op, "rra\n", 4))
		reverse_rotate(s_a, 0, vars);
	else if (!ft_strncmp(op, "rrb\n", 4))
		reverse_rotate(s_b, 1, vars);
	else if (!ft_strncmp(op, "rrr\n", 4))
		reverse_rotate_ab(s_a, s_b, vars);
	else
		error();
}

static void	get_ops_from_stdin(t_pslist **s_a, t_pslist **s_b, t_psvars **vars)
{
	char	*buffer;

	buffer = ft_strdup("42");
	while (buffer != NULL)
	{
		free(buffer);
		buffer = get_next_line(0);
		if (buffer)
			do_op(s_a, s_b, buffer, vars);
	}
}

int	main(int argc, char **argv)
{
	t_pslist	*s_a;
	t_pslist	*s_b;
	t_psvars	*vars;

	init_struct(&vars);
	populate(argc, argv, &s_a, &s_b);
	get_ops_from_stdin(&s_a, &s_b, &vars);
	check_sort_chk(&s_a, 0);
	ft_intlstclear(&s_a, &s_b);
	free(vars);
	return (0);
}
