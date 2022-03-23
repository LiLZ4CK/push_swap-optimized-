/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:08:20 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 22:20:12 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_bonus.h"

void	bonus_herror(int i)
{
	write(2, "Error\n", 5);
	write(2, "\n", 1);
	exit(i);
}

t_stacks	*stack_init_bonus(t_stacks *p)
{
	p->a = bonus_lstnew(0);
	p->b = NULL;
	return (p);
}

void	check_dup_bonus(char *argv[], int j)
{
	int		i;
	int		k;

	i = j;
	while (argv[i])
	{
		k = j;
		while (argv[k])
		{
			if ((bonus_atoi(argv[i]) - bonus_atoi(argv[k]) == 0) && i != k)
				bonus_herror(1);
			k++;
		}
		i++;
	}
}

int	check_sorted_bonus(t_stacks *p)
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

t_stacks	*bonus_operations2(t_stacks *p, char *op)
{
	if (bonus_strncmp(op, "ra") == 0)
		p->a = rotate_a_bonus(p->a);
	else if (bonus_strncmp(op, "rb") == 0)
		p->b = rotate_b_bonus(p->b);
	else if (bonus_strncmp(op, "sa") == 0)
		p->a = swap_a_bonus(p->a);
	else if (bonus_strncmp(op, "sb") == 0)
		p->b = swap_b_bonus(p->b);
	else if (bonus_strncmp(op, "rra") == 0)
		p->a = r_rotate_a_bonus(p->a);
	else if (bonus_strncmp(op, "rrb") == 0)
		p->b = r_rotate_b_bonus(p->b);
	else if (bonus_strncmp(op, "pa") == 0)
		p->a = push_a_bonus(p);
	else if (bonus_strncmp(op, "pb") == 0)
		p->b = push_b_bonus(p);
	else if (bonus_strncmp(op, "rrr") == 0)
		p = r_rotate_ab_bonus(p);
	else if (bonus_strncmp(op, "rr") == 0)
		p = rotate_ab_bonus(p);
	else if (bonus_strncmp(op, "ss") == 0)
		p = swap_ab_bonus(p);
	return (p);
}
