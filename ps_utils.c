/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:19:19 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/15 19:36:55 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	herror(int i)
{
	write(2, "Error\n", 6);
	exit(i);
}

void	check_dup(char *argv[])
{
	int		i;
	int		k;

	i = 1;
	while (argv[i])
	{
		k = 1;
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
