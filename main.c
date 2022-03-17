/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:30:17 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/16 23:41:26 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_swap	*push_three(t_swap *a)
{
	t_swap	*tmp1;
	t_swap	*tmp2;

	tmp1 = a->next;
	tmp2 = tmp1->next;
	if (a->stack > tmp1->stack && tmp1->stack > tmp2->stack)
	{
		a = swap_a(a);
		a = r_rotate_a(a);
	}
	if (a->stack > tmp1->stack && a->stack < tmp2->stack)
		a = swap_a(a);
	if (a->stack > tmp2->stack && tmp2->stack > tmp1->stack)
		a = rotate_a(a);
	if (a->stack < tmp2->stack && tmp1->stack > tmp2->stack)
	{
		a = swap_a(a);
		a = rotate_a(a);
	}
	if (a->stack < tmp1->stack && a->stack > tmp2->stack)
		a = r_rotate_a(a);
	return (a);
}

t_stacks	*push_five2(t_stacks *p)
{
	int	i;
	int	j;
	int	k;

	i = low_find(p->a);
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
		while (j < k)
		{
			p->a = r_rotate_a(p->a);
			j++;
		}
	}
	return (p);
}

void	only_two(t_swap *a)
{
	t_swap	*tmp;

	tmp = a->next;
	if (a->stack > tmp->stack)
		swap_a(a);
	exit(1);
}

t_stacks	*push_five(t_stacks *p, int i)
{
	if (i == 3)
		only_two(p->a);
	if (i == 4)
		sub_three(p->a);
	if (i == 6)
	{
		p = push_five2(p);
		p->b = push_b(p);
	}
	p = push_five2(p);
	p->b = push_b(p);
	p->a = push_three(p->a);
	p->a = push_a(p);
	if (i == 6)
		p->a = push_a(p);
	return (p);
}

int	main(int argc, char *argv[])
{
	t_stacks	p;
	int			i;

	i = 1;
	p.arg = argc - 1;
	if (argc == 2)
		herror(1);
	check_dup(argv);
	p = *stack_init(&p, argv, argc);
	while (argv[i] != NULL)
		ps_lstadd_back(p.a, ps_lstnew(ps_atoi(argv[i++])));
	p.a = p.a->next;
	if (check_sorted(&p))
		exit(1);
	if (argc <= 6)
		p = *push_five(&p, argc);
	if (argc > 6)
		ps_looot(&p);
	/* while (p.a != NULL)
	{
		printf("p.a = %d\n", p.a->stack);
		p.a = p.a->next;
	} */
	system("leaks push_swap");
	return (0);
}
