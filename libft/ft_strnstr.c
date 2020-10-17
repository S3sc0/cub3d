/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:04:29 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/04 14:59:18 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static	int	len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strnstr(const char *father, const char *son, size_t n)
{
	size_t	i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	if (len((char *)son) == 0)
		return ((char *)father);
	while (i < n && father[i] != '\0')
	{
		k = i;
		while (father[k] == son[j] && k < n && father[k] != '\0')
		{
			k++;
			j++;
		}
		if (len((char *)son) == j)
			return ((char *)&father[k - j]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
