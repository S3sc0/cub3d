/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:54:49 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/02 02:25:07 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		len(unsigned int nb, int n)
{
	int i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	if (n <= 0)
		i++;
	return (i);
}

static	void	ft_putnbr(unsigned int nb, char *str)
{
	while (nb)
	{
		*str-- = nb % 10 + 48;
		nb /= 10;
	}
}

char			*ft_itoa(int n)
{
	unsigned int	nb;
	int				length;
	char			*str;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	length = len(nb, n);
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	if (n < 0)
	{
		ft_putnbr(nb, &str[length - 1]);
		str[0] = '-';
	}
	else
		ft_putnbr(nb, &str[length - 1]);
	if (n == 0)
		str[0] = '0';
	str[length] = '\0';
	return (str);
}
