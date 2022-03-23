/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:49:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 22:29:53 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_swap	*sub_three(t_swap	*a)
{
	push_three(a);
	exit(1);
}

t_stacks	*stack_init(t_stacks *p, char *argv[], int argc, int i)
{
	int	j;

	if (argc >= 6)
	{
		p->tab = malloc(sizeof (int) * (argc - 1));
		j = 0;
		while (j < argc - 1)
		{
			p->tab[j] = ps_atoi(argv[i]);
			i++;
			j++;
		}
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

int	check_sorted(t_stacks *p, int argc)
{
	t_swap	*tmp1;
	t_swap	*tmp;

	if (argc == 1)
		exit(1);
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
