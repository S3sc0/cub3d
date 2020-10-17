/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:15:37 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/04 15:00:59 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static	int	len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int free;
	int ldst;
	int i;
	int j;

	if (!size)
		return (len((char*)src));
	i = 0;
	ldst = len(dst);
	j = ldst;
	free = size - ldst;
	if ((size_t)ldst > size)
		return (len((char *)src) + size);
	else
	{
		while (i < free - 1 && i < len((char *)src))
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	return (ldst + len((char *)src));
}
