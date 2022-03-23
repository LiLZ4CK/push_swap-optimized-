/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_a_hermanos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:56:43 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 21:15:23 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_bonus.h"

t_swap	*push_a_bonus(t_stacks *p)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	if (p->b == NULL)
		return (p->a);
		tmp = p->b;
	tmp2 = bonus_lstnew(p->b->stack);
	p->a = bonus_lstadd_front(p->a, tmp2);
	p->b = p->b->next;
	free(tmp);
	return (p->a);
}

t_swap	*swap_a_bonus(t_swap *a)
{
	int		tmp;

	if (a == NULL)
		return (a);
	tmp = a->stack;
	a->stack = a->next->stack;
	a->next->stack = tmp;
	return (a);
}

t_swap	*rotate_a_bonus(t_swap *a)
{
	int		i;
	t_swap	*tmp;
	t_swap	*tmp2;

	if ((a == NULL) || (a->next == NULL))
		return (a);
	i = a->stack;
	tmp = a;
	a = a->next;
	tmp2 = bonus_lstnew(i);
	bonus_lstadd_back(a, tmp2);
	tmp->next = NULL;
	free(tmp);
	return (a);
}

t_swap	*r_rotate_a_bonus(t_swap *a)
{
	t_swap	*tmp1;
	t_swap	*tmp2;
	t_swap	*tmp3;

	if ((a == NULL) || (a->next == NULL))
		return (a);
	tmp1 = a;
	tmp2 = a;
	tmp3 = bonus_lstlast(a);
	a = bonus_lstadd_front(a, bonus_lstnew(tmp3->stack));
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	free(tmp1);
	return (a);
}
