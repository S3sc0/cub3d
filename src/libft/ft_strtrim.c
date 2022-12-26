/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:34:00 by aamzouar          #+#    #+#             */
/*   Updated: 2019/10/30 21:48:48 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static	char	*front(char *s2, char *set1)
{
	int i;
	int j;

	i = 0;
	while (s2[i] != '\0')
	{
		j = 0;
		while (s2[i] != set1[j])
		{
			if (j == len(set1))
				return (&s2[i]);
			j++;
		}
		i++;
	}
	return (&s2[i]);
}

static	int		back(char *s3, char *set2)
{
	int i;
	int last;

	last = len(s3);
	while (last != 0)
	{
		i = 0;
		while (s3[last] != set2[i])
		{
			if (i == len(set2))
			{
				return (last);
			}
			i++;
		}
		last--;
	}
	return (0);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		s;
	int		i;
	char	*final;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	final = front((char *)s1, (char *)set);
	if (len((char *)s1) == 0)
		s = 0;
	else
		s = back(final, (char *)set) + 1;
	if (!(str = (char *)malloc(sizeof(char) * s + 1)))
		return (NULL);
	while (final[i] != '\0' && i < s)
	{
		str[i] = final[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
