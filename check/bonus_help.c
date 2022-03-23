/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:24:55 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 21:32:31 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_bonus.h"

t_stacks	*fix_zsh_bonus(char *argv[], t_stacks *p)
{
	int		i;
	char	**av;
	t_swap	*tmp;

	i = 0;
	av = bonus_split(argv[1], ' ');
	while (av[i] != NULL)
		i++;
	check_dup_bonus(av, 0);
	p = stack_init_bonus(p);
	p->arg = i;
	i = 0;
	tmp = p->a;
	while (av[i] != NULL)
		bonus_lstadd_back(p->a, bonus_lstnew(bonus_atoi(av[i++])));
	p->a = p->a->next;
	free(tmp);
	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (p);
}

t_stacks	*bonus_main(t_stacks *p, char *argv[], int argc)
{
	int		i;
	t_swap	*tmp;

	i = 1;
	p->arg = argc - 1;
	check_dup_bonus(argv, 1);
	p = stack_init_bonus(p);
	while (argv[i] != NULL)
		bonus_lstadd_back(p->a, bonus_lstnew(bonus_atoi(argv[i++])));
	tmp = p->a;
	p->a = p->a->next;
	free(tmp);
	return (p);
}
