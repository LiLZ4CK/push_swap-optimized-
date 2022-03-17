/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:58:36 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/16 15:44:55 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

size_t	ps_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ps_isdigit(char c)
{
	if ((c >= '0' && c <= '9') || c == '\0')
	{
		return (1);
	}
	return (0);
}

int	ps_atoi(char *str)
{
	int		i;
	int		j;
	long	n;
	long	c;

	i = 0;
	j = 1;
	n = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-')
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	if (!ps_isdigit(str[i]))
		herror(1);
	c = j * n;
	if ((c > 2147483647) || (c < -2147483648))
		herror(1);
	return (c);
}

void	ps_lstdelone(t_swap *x, int i)
{
	t_swap	*tmp;

	tmp = x;
	if (i == 1)
	{
		tmp = NULL;
		free(tmp);
	}
	if (i == 2)
	{
		while (tmp->next == NULL)
			tmp = tmp->next;
		tmp = NULL;
		free(tmp);
	}
}
