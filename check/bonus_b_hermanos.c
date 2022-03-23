/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_b_hermanos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:01:34 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 21:17:36 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_bonus.h"

t_swap	*push_b_bonus(t_stacks *p)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	if (p->a == NULL)
		return (p->b);
	tmp = p->a;
	tmp2 = bonus_lstnew(p->a->stack);
	p->b = bonus_lstadd_front(p->b, tmp2);
	p->a = p->a->next;
	free(tmp);
	return (p->b);
}

t_swap	*swap_b_bonus(t_swap *b)
{
	int	tmp;

	if ((b == NULL) || (b->next == NULL))
		return (b);
	tmp = b->stack;
	b->stack = b->next->stack;
	b->next->stack = tmp;
	return (b);
}

t_swap	*rotate_b_bonus(t_swap *b)
{
	int		i;
	t_swap	*tmp;
	t_swap	*tmp2;

	if ((b == NULL) || (b->next == NULL))
		return (b);
	i = b->stack;
	tmp = b;
	b = b->next;
	tmp2 = bonus_lstnew(i);
	bonus_lstadd_back(b, tmp2);
	tmp2 = NULL;
	tmp->next = NULL;
	free(tmp2);
	free(tmp);
	return (b);
}

t_swap	*r_rotate_b_bonus(t_swap *b)
{
	t_swap	*tmp1;
	t_swap	*tmp2;
	t_swap	*tmp3;

	if ((b == NULL) || (b->next == NULL))
		return (b);
	tmp1 = b;
	tmp2 = b;
	tmp3 = bonus_lstlast(b);
	b = bonus_lstadd_front(b, bonus_lstnew(tmp3->stack));
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	free(tmp1);
	return (b);
}
