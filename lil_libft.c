/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:58:36 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/15 19:36:47 by zwalad           ###   ########.fr       */
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
	int	i;
	int	j;
	int	n;
	int	c;

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

char	*ps_strdup(char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(ps_strlen(s1) + 1);
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ps_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	t;

	i = 0;
	if (!s)
		return (NULL);
	t = ps_strlen(s);
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
