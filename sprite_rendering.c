/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:21:29 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 16:50:25 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calc_dst(float rayAngle, player plr)
{
	float	ret;

	ret = sqrt(pow(plr.x - sprt.x, 2) + pow(plr.y - sprt.y, 2));
	ret *= cos((rayAngle - plr.rotationA) * RADIN);
	return (ret);
}

void	sprite_rendering(player plr, float rayAngle)
{
	float	dst;

	dst = calc_dst(rayAngle, plr);
}
