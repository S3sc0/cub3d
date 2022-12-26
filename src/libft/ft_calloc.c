/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:30:17 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/04 13:54:14 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*str;

	i = size * count;
	if (!(str = malloc(i)))
		return (0);
	while (i--)
		str[i] = 0;
	return (str);
}
