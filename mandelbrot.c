/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:46 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/22 14:36:48 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractol	*init(t_fractol *info)
{
	info->x = 0;
	info->x1 = -2.1;
	info->x2 = 0.6;
	info->y1 = -1.2;
	info->y2 = 1.2;
	info->image_x = WSIZE;
	info->image_y = WSIZE;
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
		info->img_int[info->x + info->y * WSIZE] = 0x000000;
	else
		info->img_int[info->x + info->y * WSIZE] = 20000 * i;
}

void				mandelbrot(t_fractol *info)
{
	info = init(info);
	while (info->x < WSIZE)
	{
		info->y = 0;
		while (info->y < WSIZE)
		{
			draw(info);
			info->y++;
		}
		info->x++;
	}
}
