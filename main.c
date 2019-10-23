/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:58:48 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/15 17:39:40 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WSIZE, WSIZE, "fractol");
	info->img = mlx_new_image(info->mlx, WSIZE, WSIZE);
	info->img_int = (int *)mlx_get_data_addr(info->img, &info->bpp,
		&info->lsize, &info->endian);
}

int	main()
{
	t_fractol *info;

	if (!(info = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	init(info);
	mandelbrot(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_loop(info->mlx);
	return (0);
}
