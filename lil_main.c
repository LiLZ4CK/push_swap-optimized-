/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:49:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/15 21:38:57 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_swap	*sub_three(t_swap	*a)
{
	push_three(a);
	exit(1);
}

t_stacks	*stack_init(t_stacks *p, char *argv[], int argc)
{
	int	i;

	p->tab = malloc(sizeof (int) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		p->tab[i] = ps_atoi(argv[i + 1]);
		i++;
	}
	p->a = ps_lstnew(0);
	p->b = NULL;
	return (p);
}

int	le_index(int i, t_swap *a)
{
	int	j;

	j = 0;
	while (a != NULL)
	{
		if (a->stack == i)
			return (j);
		j++;
		a = a->next;
	}
	return (j);
}

int	low_find(t_swap *a)
{
	int		i;

	i = a->stack;
	while (a != NULL)
	{
		if (a->stack < i)
			i = a->stack;
		a = a->next;
	}
	return (i);
}

int	check_sorted(t_stacks *p)
{
	t_swap	*tmp1;
	t_swap	*tmp;

	tmp = p->a;
	while (tmp->next != NULL)
	{
		tmp1 = tmp->next;
		if (tmp1->stack < tmp->stack)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
