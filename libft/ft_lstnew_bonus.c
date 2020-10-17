/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:07:10 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/04 14:36:12 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *new_content;

	if (!(new_content = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
