/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:52:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/16 15:58:06 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_stacks	*sort_tab(t_stacks *p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < p->arg)
	{
		j = i + 1;
		while (j < p->arg)
		{
			if (p->tab[i] > p->tab[j])
			{
				k = p->tab[i];
				p->tab[i] = p->tab[j];
				p->tab[j] = k;
			}
			j++;
		}
		i++;
	}
	return (p);
}

int	lower_find(t_swap *a, int low)
{
	while (a != NULL)
	{
		if (a->stack <= low)
			return (a->stack);
		a = a->next;
	}
	return (a->stack);
}

t_stacks	*get_lower(t_stacks *p, int low)
{
	int	i;
	int	j;
	int	k;

	i = lower_find(p->a, low);
	j = le_index(i, p->a);
	k = le_len(p->a);
	if (j <= (k / 2))
	{
		while (j >= 1)
		{
			p->a = rotate_a(p->a);
			j--;
		}
	}
	else if (j > (k / 2))
	{
		while (j <= k)
		{
			p->a = r_rotate_a(p->a);
			j++;
		}
	}
	return (p);
}

t_swap	*get_highest(t_swap *b, int i)
{
	int	j;
	int	k;

	j = le_index(i, b);
	k = le_len(b);
	if (j <= (k / 2))
	{
		while (j >= 1)
		{
			b = rotate_b(b);
			j--;
		}
	}
	if (j > (k / 2))
	{
		while (j < k)
		{
			b = r_rotate_b(b);
			j++;
		}
	}
	return (b);
}
