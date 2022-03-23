/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:50:35 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 22:19:11 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_bonus.h"

t_stacks	*bonus_operations(t_stacks *p, char *op)
{
	if ((bonus_strncmp(op, "ra") == 0) || (bonus_strncmp(op, "rb") == 0)
		|| (bonus_strncmp(op, "sa") == 0) || (bonus_strncmp(op, "sb") == 0)
		|| (bonus_strncmp(op, "rra") == 0) || (bonus_strncmp(op, "rrb") == 0)
		|| (bonus_strncmp(op, "pa") == 0) || (bonus_strncmp(op, "pb") == 0)
		|| (bonus_strncmp(op, "rrr") == 0) || (bonus_strncmp(op, "rr") == 0)
		|| (bonus_strncmp(op, "ss") == 0))
		bonus_operations2(p, op);
	else
	{
		bonus_herror(1);
	}
	return (p);
}

int	main(int argc, char *argv[])
{
	t_stacks	p;
	char		*op;

	if (argc == 1)
		exit(1);
	if (argc > 2)
		p = *bonus_main(&p, argv, argc);
	if (argc == 2)
		p = *fix_zsh_bonus(argv, &p);
	op = get_next_line(0);
	while (op != NULL)
	{
		p = *bonus_operations(&p, op);
		free(op);
		op = get_next_line(0);
	}
	if (check_sorted_bonus(&p) && (p.b == NULL))
	{
		ft_printf("OK\n");
		exit(1);
	}
	ft_printf("KO\n");
	return (0);
}
