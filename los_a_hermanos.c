/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   los_a_hermanos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:56:43 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/17 01:36:54 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_swap	*push_a(t_stacks *p)
{
	t_swap	*tmp;
	t_swap	*tmp2;
	int		i;
	
	tmp = p->b;
	i = p->b->stack;
	tmp2 = ps_lstnew(i);
	p->a = ps_lstadd_front(p->a, tmp2);
	p->b = p->b->next;
	ft_printf("pa\n");
	tmp2 = NULL;
	tmp->next = NULL;
	free(tmp2);
	free(tmp);
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
	int		i;

	i = ps_lstlast(a)->stack;
	tmp1 = ps_lstnew(i);
	a = ps_lstadd_front(a, tmp1);
	tmp1 = NULL;
	free(tmp1);
	ft_printf("rra\n");
	return (a);
}
