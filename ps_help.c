/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:52:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 16:13:20 by zwalad           ###   ########.fr       */
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

t_stacks	*fix_zsh(char *argv[], t_stacks *p)
{
	int		i;
	char	**av;
	t_swap	*tmp;

	i = 0;
	av = ps_split(argv[1], ' ');
	while (av[i] != NULL)
		i++;
	if (av[0] == NULL)
		herror(1);
	check_dup(av, 0);
	p = stack_init(p, av, (i + 1), 0);
	p->arg = i;
	i = 0;
	tmp = p->a;
	while (av[i] != NULL)
		ps_lstadd_back(p->a, ps_lstnew(ps_atoi(av[i++])));
	p->a = p->a->next;
	free(tmp);
	i = 0;
	while (av[i] != NULL)
		free(av[i++]);
	free(av);
	return (p);
}
