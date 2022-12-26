/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:15:25 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/02 01:45:41 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		count(char *p, char c)
{
	int	i;
	int count;

	count = 0;
	i = 0;
	if (*p == '\0')
		return (0);
	while (p[i] == c)
		i++;
	while (p[i] != '\0')
	{
		if ((p[i] == c && p[i + 1] != c) || (p[i] != c && p[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	int		letters(char *p, char c)
{
	int i;

	i = 0;
	while (p[i] != c && p[i] != '\0')
		i++;
	return (i);
}

static	char	**fill(char *p, char c, char **str)
{
	int j;
	int h;
	int f_count;

	f_count = count(p, c);
	j = 0;
	while (j < f_count)
	{
		h = 0;
		while (*p == c)
			p++;
		while (*p != c && *p != '\0')
		{
			str[j][h] = *p++;
			h++;
		}
		str[j][h] = '\0';
		j++;
	}
	str[j] = 0;
	return (str);
}

static	char	**ft_free(int b, char **str)
{
	while (b)
		free(str[b--]);
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		m;
	int		l;
	char	*st;
	int		b;

	if (s == NULL)
		return (NULL);
	b = -1;
	st = (char *)s;
	m = count((char *)s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (m + 1))))
		return (NULL);
	while (++b < m)
	{
		while (*s == c)
			s++;
		l = letters((char *)s, c);
		if (!(str[b] = (char *)malloc(sizeof(char) * (l + 1))))
			return (ft_free(b, str));
		while (*s != c && *s != '\0')
			s++;
	}
	return (fill(st, c, str));
}
