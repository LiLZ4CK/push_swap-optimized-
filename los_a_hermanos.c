/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   los_a_hermanos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:56:43 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/09 19:42:35 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_swap	*push_a(t_stacks *p)
{
	p->free_b = p->b;
	p->a = ps_lstadd_front(p->a, ps_lstnew(p->b->stack));
	p->b = p->b->next;
	ft_printf("pa\n");
	return (p->a);
}

t_swap	*swap_a(t_swap *a)
{
	t_swap	*tmp1;
	t_swap	*tmp2;
	int		j;
	int		i;

	tmp1 = a;
	tmp2 = a->next;
	i = tmp1->stack;
	a = a->next;
	j = tmp2->stack;
	a = a->next;
	a = ps_lstadd_front(a, ps_lstnew(i));
	a = ps_lstadd_front(a, ps_lstnew(j));
	ft_printf("sa\n");
	return (a);
}

t_swap	*rotate_a(t_swap *a)
{
	int		i;

	i = a->stack;
	a = a->next;
	ps_lstadd_back(a, ps_lstnew(i));
	ft_printf("ra\n");
	return (a);
}

t_swap	*r_rotate_a(t_swap *a)
{
	t_swap	*tmp1;
	t_swap	*tmp2;
	t_swap	*tmp3;

	tmp1 = a;
	tmp2 = a;
	tmp3 = ps_lstlast(a);
	a = ps_lstadd_front(a, ps_lstnew(tmp3->stack));
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	ft_printf("rra\n");
	return (a);
}
