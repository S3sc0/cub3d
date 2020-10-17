/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:31:51 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/02 14:29:40 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		sum;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	j = 0;
	i = 0;
	sum = len((char *)s1) + len((char *)s2);
	if (!(ptr = (char *)malloc(sizeof(char) * sum + 1)))
		return (NULL);
	while (i < len((char *)s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < sum)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
