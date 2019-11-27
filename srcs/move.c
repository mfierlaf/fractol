/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:13:49 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/23 17:13:52 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	move(int x, int y, t_fractol *info)
{
	if (info->name == 2 && info->move == 0)
	{
		info->modx = (double)x / WHIGH;
		info->mody = (double)y / WWIDT;
		mlx_destroy_image(info->mlx, info->img);
		info->img = mlx_new_image(info->mlx, WHIGH, WWIDT);
		info->img_int = (int *)mlx_get_data_addr(info->img, &info->bpp,
			&info->lsize, &info->endian);
		julia_pthread(info);
		mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	}
	return (1);
}
