/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop_hoock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:51:13 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/23 15:53:24 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_loop_hoock(t_fractol *info)
{
	mlx_destroy_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, WHIGH, WWIDT);
	info->img_int = (int *)mlx_get_data_addr(info->img, &info->bpp,
			&info->lsize, &info->endian);
	if (info->color_flag == 1)
		info->color += 1000;
	if (info->name == 1)
		mandelbrot_pthread(info);
	else if (info->name == 2)
		julia_pthread(info);
	else if (info->name == 3)
		burning_ship_pthread(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	if (info->name == 2)
		mlx_hook(info->win, MOTIONNOTIFY, POINTERMOTIONMASK, move, info);
	return (1);
}
