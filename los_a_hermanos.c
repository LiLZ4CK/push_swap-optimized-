/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   los_a_hermanos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:56:43 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 21:39:42 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_swap	*push_a(t_stacks *p)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = p->b;
	tmp2 = ps_lstnew(p->b->stack);
	p->a = ps_lstadd_front(p->a, tmp2);
	p->b = p->b->next;
	ft_printf("pa\n");
	free(tmp);
	return (p->a);
}

t_swap	*swap_a(t_swap *a)
{
	int	tmp;

	tmp = a->stack;
	a->stack = a->next->stack;
	a->next->stack = tmp;
	ft_printf("sa\n");
	return (a);
}

t_swap	*rotate_a(t_swap *a)
{
	int		i;
	t_swap	*tmp;
	t_swap	*tmp2;

	i = a->stack;
	tmp = a;
	a = a->next;
	tmp2 = ps_lstnew(i);
	ps_lstadd_back(a, tmp2);
	ft_printf("ra\n");
	tmp->next = NULL;
	free(tmp);
	return (a);
}

t_swap	*r_rotate_a(t_swap *a)
{
	t_swap	*tmp1;
	t_swap	*tmp2;
	t_swap	*tmp3;

	if ((a == NULL) || (a->next == NULL))
		return (a);
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
	free(tmp1);
	ft_printf("rra\n");
	return (a);
}
