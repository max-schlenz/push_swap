/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:06:11 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/29 11:38:41 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	ft_intlstsize(t_pslist *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i + 1);
}

t_pslist	*ft_intlstnew(long content, size_t index)
{
	t_pslist	*list;

	list = malloc(sizeof(t_pslist));
	if (!list)
		return (NULL);
	list->content = content;
	list->index = index;
	list->next = NULL;
	return (list);
}
