/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:39:05 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/04 15:50:09 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}
