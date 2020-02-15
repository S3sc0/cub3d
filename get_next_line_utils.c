/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:58:14 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/22 22:19:47 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*buf;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		buf[i] = s1[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		sum;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	j = ft_strlen((char *)s1);
	i = 0;
	sum = j + ft_strlen((char *)s2);
	if (!(ptr = (char *)malloc(sizeof(char) * sum + 1)))
		return (NULL);
	while (i < j)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < sum)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s1;

	if (!s)
		return (NULL);
	if ((int)start > ft_strlen(s))
		len = 0;
	i = 0;
	if (!(s1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
