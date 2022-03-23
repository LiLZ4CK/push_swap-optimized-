/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_libft2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:49:40 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/22 21:46:27 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_bonus.h"

char	*bonus_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	t;

	i = 0;
	if (!s)
		return (NULL);
	t = bonus_strlen(s);
	if (len > t + 1)
		len = t + 1;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (len > 0 && start + i <= t && s[start + i])
	{
		str[i] = s[start + i];
		i++;
		len --;
	}
	str[i] = '\0';
	return (str);
}

static int	ps_wnb( char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[0] != c && i == 0) || (str[i] != c && str[i - 1] == c))
		{
			i++;
			j++;
		}
		if (str[i])
			i++;
	}
	return (j);
}

static void	ps_free(char **str, int wnbr)
{
	int	i;

	i = 0;
	while (i < wnbr)
	{
		free(str[i]);
		i++;
	}
}

static void	alloc(char **sp, char *s, char c, int wnbr)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	while (j < wnbr - 1)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
			index = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		sp [j] = bonus_substr(s, index, i - index);
		if (!sp[j])
		{
			ps_free(sp, j);
			break ;
		}
		j++;
	}
	sp[j] = NULL;
}

char	**bonus_split(char *s, char c)
{
	char	**str;
	int		wnbr;

	if (s == NULL)
		return (NULL);
	wnbr = ps_wnb(s, c) + 1;
	str = malloc(sizeof(char *) * wnbr);
	if (str == NULL)
		return (NULL);
	alloc(str, s, c, wnbr);
	return (str);
}
