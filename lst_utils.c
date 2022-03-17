/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:53:47 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/16 23:43:30 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

int	ps_lstsize(t_swap *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_swap	*ps_lstlast(t_swap *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_swap	*ps_lstnew(int content)
{
	t_swap	*p;

	p = NULL;
	p = (t_swap *)malloc(sizeof(t_swap));
	if (!p)
		return (0);
	p->stack = content;
	p->next = NULL;
	return (p);
}

void	ps_lstadd_back(t_swap *lst, t_swap *new)
{
	if (lst == NULL)
		lst = new;
	else
	{
		ps_lstlast(lst)->next = new;
	}
}

t_swap	*ps_lstadd_front(t_swap *lst, t_swap *new)
{
	new->next = lst;
	lst = new;
	return (lst);
}
