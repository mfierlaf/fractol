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

#include "../includes/fractol.h"

static	int	identification(char **argv, t_fractol *info)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		info->name = 1;
		info = start_mandelbrot(info);
		mandelbrot_pthread(info);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		info->name = 2;
		info = start_julia(info);
		julia_pthread(info);
	}
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
	{
		info->name = 3;
		info = start_burning_ship(info);
		burning_ship_pthread(info);
	}
	else
	{
		ft_printf("this program use those fractal:\n\
				julia, mandelbrot, burning_ship");
		return (-1);
	}
	return (0);
}

static void	init(t_fractol *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WHIGH, WWIDT, "fractol");
	info->img = mlx_new_image(info->mlx, WHIGH, WWIDT);
	info->img_int = (int *)mlx_get_data_addr(info->img, &info->bpp,
		&info->lsize, &info->endian);
	info->color = 1;
	info->color_flag = 0;
	info->move = 0;
}

int			main(int argc, char **argv)
{
	int			(*key)(int, void*);
	t_fractol	*info;

	if (argc != 2)
	{
		ft_printf("Usage : ./fractol [fractal]");
		return (-1);
	}
	key = &key_push;
	if (!(info = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	init(info);
	if (identification(argv, info) == -1)
		return (-1);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_mouse_hook(info->win, mouse_hook, info);
	mlx_key_hook(info->win, key, info);
	mlx_loop_hook(info->mlx, key_loop_hoock, info);
	mlx_hook(info->win, MOTIONNOTIFY, POINTERMOTIONMASK, move, info);
	mlx_loop(info->mlx);
	return (0);
}
