/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:58:41 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/09 16:39:07 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normA(float angle)
{
	if (angle > 360)
		return (angle - 360);
	else if (angle < 0)
		return (angle + 360);
	return (angle);
}
