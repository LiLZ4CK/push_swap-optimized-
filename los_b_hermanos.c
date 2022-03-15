/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   los_b_hermanos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:01:34 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/09 19:42:46 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_swap	*push_b(t_stacks *p)
{
	p->free_a = p->a;
	p->b = ps_lstadd_front(p->b, ps_lstnew(p->a->stack));
	p->a = p->a->next;
	ft_printf("pb\n");
	return (p->b);
}

t_swap	*swap_b(t_swap *b)
{
	t_swap	*tmp1;
	t_swap	*tmp2;
	int		j;
	int		i;

	tmp1 = b;
	tmp2 = b->next;
	i = tmp1->stack;
	b = b->next;
	j = tmp2->stack;
	b = b->next;
	b = ps_lstadd_front(b, ps_lstnew(i));
	b = ps_lstadd_front(b, ps_lstnew(j));
	ft_printf("sb\n");
	return (b);
}

t_swap	*rotate_b(t_swap *b)
{
	int		i;

	i = b->stack;
	b = b->next;
	ps_lstadd_back(b, ps_lstnew(i));
	ft_printf("rb\n");
	return (b);
}

t_swap	*r_rotate_b(t_swap *b)
{
	t_swap	*tmp1;
	t_swap	*tmp2;
	t_swap	*tmp3;

	tmp1 = b;
	tmp2 = b;
	tmp3 = ps_lstlast(b);
	b = ps_lstadd_front(b, ps_lstnew(tmp3->stack));
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	ft_printf("rrb\n");
	return (b);
}
