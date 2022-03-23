/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:48:46 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 17:24:49 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_stacks	*ps_indixing(t_stacks *p)
{
	int		i;
	t_swap	*tmp;

	tmp = p->a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < p->arg)
		{
			if (tmp->stack == p->tab[i])
			{
				tmp->stack = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (p);
}

t_stacks	*ps_push_to_b(t_stacks *p)
{
	int		i;
	int		low;

	i = 0;
	low = 0;
	while (p->a != NULL)
	{
		i = 0;
		low = low + (p->arg / 10) + 1;
		while (i < ((p->arg / 10) + 1) && p->a != NULL)
		{
			if (p->a->stack <= low)
			{
				p->b = push_b(p);
				i++;
			}
			else if (p->a->stack > low && p->a != NULL)
				p = get_lower(p, low);
		}
	}
	return (p);
}

void	ps_looot(t_stacks *p)
{
	int	i;

	p = sort_tab(p);
	p = ps_indixing(p);
	p = ps_push_to_b(p);
	i = p->arg - 1;
	while (p->b != NULL)
	{
		if (p->b->stack == i)
		{
			p->a = push_a(p);
			i--;
		}
		else if (p->b->stack != i)
		{
			p->b = get_highest(p->b, i);
			if (p->b->stack == i)
			{
				p->a = push_a(p);
				i--;
			}
		}
	}
}
