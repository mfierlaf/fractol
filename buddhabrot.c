/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:11:59 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/23 16:12:04 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractol	*start(t_fractol *info)
{
	info->x = -500;
	info->x1 = -2.1;
	info->x2 = 0.6;
	info->y1 = -1.2;
	info->y2 = 1.2;
	info->image_x = WHIGH;
	info->image_y = WWIDT;
	info->it_max = 50;
	info->zoom_x = info->image_x / (info->x2 - info->x1);
	info->zoom_y = info->image_y / (info->y2 - info->y1);
	return (info);
}

static void			draw(t_fractol *info)
{
	int i;

	info->c_r = info->x / info->zoom_x + info->x1;
	info->c_i = info->y / info->zoom_y + info->y1;
	info->z_r = 0;
	info->z_i = 0;
	i = 0;
	while (info->z_r * info->z_r + info->z_i * info->z_i < 4 &&
		i < info->it_max)
		{
			info->tmp = info->z_r;
			info->z_r = info->z_r * info->z_r - info->z_i * info->z_i +
			info->c_r;
			info->z_i = 2 * info->z_i * info->tmp + info->c_i;
			i = i + 1;
		}
	if (i == info->it_max)
		info->img_int[info->x + info->y * WHIGH] = 0x000000;
	else
		info->img_int[info->x + info->y * WHIGH] = info->color * i * 10;
}

void				buddhabrot(t_fractol *info)
{
	info = start(info);
	while (info->x < WHIGH)
	{
		info->y = 0;
		while (info->y < WWIDT)
		{
			draw(info);
			info->y++;
		}
		info->x++;
	}
}
