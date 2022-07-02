/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:46:54 by mschlenz          #+#    #+#             */
/*   Updated: 2022/06/28 18:06:02 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_intlstdelone(t_pslist *lst)
{
	if (!lst)
		return ;
	free (lst);
}

void	ft_intlstclear(t_pslist **s_a, t_pslist **s_b)
{
	t_pslist	*buf_list;

	if (!s_a)
		return ;
	while (*s_a)
	{
		buf_list = (*s_a)->next;
		ft_intlstdelone(*s_a);
		*s_a = buf_list;
	}
	if (!s_b)
		return ;
	while (*s_b)
	{
		buf_list = (*s_b)->next;
		ft_intlstdelone(*s_b);
		*s_b = buf_list;
	}
}

t_pslist	*ft_intlstlast(t_pslist *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_intlstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*list;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list = ft_intlstlast(*lst);
	if (list)
		list->next = new;
}

void	ft_intlstadd_front(t_pslist **lst, t_pslist *new)
{
	if (lst && new)
	{	
		new->next = *lst;
		*lst = new;
	}
}
