/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:03:48 by mschlenz          #+#    #+#             */
/*   Updated: 2022/07/01 18:15:05 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

long	ft_ps_atoi(const char *str)
{
	int		i;
	long	r;
	int		is_neg;

	i = 0;
	r = 0;
	is_neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		is_neg = -1;
	i++;
	}
	while (ft_isdigit(str[i]))
	{
	r = r * 10 + str[i] - '0';
	i++;
	}
	if (ft_isdigit(str[i - 1]) == 0 || str[i] != '\0' \
						|| r > INT_MAX || r < INT_MIN)
		error();
	return (r * is_neg);
}

size_t	get_shortest_path(t_pslist **stack, size_t start, size_t end)
{
	size_t		i;
	size_t		counter_first_elem;
	size_t		counter_last_elem;
	t_pslist	*tmp_stack;

	i = 1;
	counter_first_elem = 0;
	counter_last_elem = 0;
	tmp_stack = *stack;
	while (tmp_stack)
	{
		i++;
		counter_last_elem++;
		if (tmp_stack->index <= end)
		{
			if (counter_first_elem == 0 && tmp_stack->index > start)
				counter_first_elem = i;
			if (tmp_stack->index > start)
				counter_last_elem = 1;
		}
		tmp_stack = tmp_stack->next;
	}
	if (counter_first_elem < counter_last_elem)
		return (1);
	return (0);
}

size_t	get_path_to_elem(t_pslist **stack, size_t index)
{
	size_t		i;
	t_pslist	*tmp_stack;

	i = 0;
	tmp_stack = *stack;
	while (tmp_stack)
	{
		i++;
		if (tmp_stack->index == index)
			break ;
		tmp_stack = tmp_stack->next;
	}
	if (i < (ft_intlstsize(*stack) / 2))
		return (1);
	return (0);
}

size_t	find_elem_in_stack(t_pslist **stack, long num)
{
	t_pslist	*tmp_stack;
	int			i;

	tmp_stack = *stack;
	i = 1;
	while (tmp_stack)
	{
		if (tmp_stack->content == num)
			return (i);
		i++;
		tmp_stack = tmp_stack->next;
	}
	return (0);
}

size_t	find_smallest_pos(t_pslist **stack)
{
	t_pslist	*tmp_stack;
	long		tmp_elem;

	tmp_stack = *stack;
	tmp_elem = tmp_stack->content;
	while (tmp_stack)
	{
		if (tmp_elem > tmp_stack->content)
			tmp_elem = tmp_stack->content;
		tmp_stack = tmp_stack->next;
	}
	return (find_elem_in_stack(stack, tmp_elem));
}
