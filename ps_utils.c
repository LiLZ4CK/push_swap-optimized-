/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:19:19 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 21:40:17 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	herror(int i)
{
	write(2, "Error\n", 5);
	write(2, "\n", 1);
	exit(i);
}

void	check_dup(char *argv[], int j)
{
	int		i;
	int		k;

	i = j;
	while (argv[i])
	{
		k = j;
		while (argv[k])
		{
			if ((ps_atoi(argv[i]) - ps_atoi(argv[k]) == 0) && i != k)
				herror(1);
			k++;
		}
		i++;
	}
}

int	le_len(t_swap	*a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stacks	*mini_main(t_stacks *p, int argc, char *argv[])
{
	int		i;
	t_swap	*tmp;

	i = 1;
	p->arg = argc - 1;
	check_dup(argv, 1);
	p = stack_init(p, argv, argc, 1);
	while (argv[i] != NULL)
		ps_lstadd_back(p->a, ps_lstnew(ps_atoi(argv[i++])));
	tmp = p->a;
	p->a = p->a->next;
	free(tmp);
	return (p);
}
