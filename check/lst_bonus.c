/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:18:16 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/17 16:20:26 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_bonus.h"

int	bonus_lstsize(t_swap *lst)
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

t_swap	*bonus_lstlast(t_swap *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_swap	*bonus_lstnew(int content)
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

void	bonus_lstadd_back(t_swap *lst, t_swap *new)
{
	if (lst == NULL)
		lst = new;
	else
	{
		bonus_lstlast(lst)->next = new;
	}
}

t_swap	*bonus_lstadd_front(t_swap *lst, t_swap *new)
{
	new->next = lst;
	lst = new;
	return (lst);
}
