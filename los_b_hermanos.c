/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   los_b_hermanos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:01:34 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 21:40:00 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_swap	*push_b(t_stacks *p)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = p->a;
	tmp2 = ps_lstnew(p->a->stack);
	p->b = ps_lstadd_front(p->b, tmp2);
	p->a = p->a->next;
	ft_printf("pb\n");
	free(tmp);
	return (p->b);
}

t_swap	*swap_b(t_swap *b)
{
	int	tmp;

	tmp = b->stack;
	b->stack = b->next->stack;
	b->next->stack = tmp;
	ft_printf("sb\n");
	return (b);
}

t_swap	*rotate_b(t_swap *b)
{
	int		i;
	t_swap	*tmp;
	t_swap	*tmp2;

	i = b->stack;
	tmp = b;
	b = b->next;
	tmp2 = ps_lstnew(i);
	ps_lstadd_back(b, tmp2);
	ft_printf("rb\n");
	tmp2 = NULL;
	tmp->next = NULL;
	free(tmp2);
	free(tmp);
	return (b);
}

t_swap	*r_rotate_b(t_swap *b)
{
	t_swap	*tmp1;
	t_swap	*tmp3;

	tmp1 = ps_lstlast(b);
	b = ps_lstadd_front(b, ps_lstnew(tmp1->stack));
	tmp3 = b;
	while (tmp3->next->next != NULL)
		tmp3 = tmp3->next;
	tmp3->next = NULL;
	free(tmp1);
	ft_printf("rrb\n");
	return (b);
}
