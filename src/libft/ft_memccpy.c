/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:11:50 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/04 16:46:05 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		if (*(char *)src == (unsigned char)c)
		{
			*(char *)dst++ = *(char *)src++;
			return (dst);
		}
		*(char *)dst++ = *(char *)src++;
	}
	return (NULL);
}
