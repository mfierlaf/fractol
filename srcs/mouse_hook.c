/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:21:03 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/11/19 15:21:08 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	t_fractol	*ft_zoom(int x, int y, t_fractol *info)
{
	info->x1 = ((double)x / info->zoom_x + info->x1) -\
		((double)x / (info->zoom_x * 1.3));
	info->y1 = ((double)y / info->zoom_y + info->y1) -\
		((double)y / (info->zoom_y * 1.3));
	info->zoom_x *= 1.3;
	info->zoom_y *= 1.3;
	info->it_max++;
	return (info);
}

static	t_fractol	*ft_dezoom(int x, int y, t_fractol *info)
{
	info->x1 = ((double)x / info->zoom_x + info->x1) -
	((double)x / (info->zoom_x / 1.3));
	info->y1 = ((double)y / info->zoom_y + info->y1) -
	((double)y / (info->zoom_y / 1.3));
	info->zoom_x /= 1.3;
	info->zoom_y /= 1.3;
	info->it_max--;
	return (info);
}

int					mouse_hook(int mouse2, int x, int y, t_fractol *info)
{
	if (mouse2 == 5)
		ft_zoom(x, y, info);
	else if (mouse2 == 4)
		ft_dezoom(x, y, info);
	if (info->name == 1)
		mandelbrot_pthread(info);
	if (info->name == 2)
		julia_pthread(info);
	if (info->name == 3)
		burning_ship_pthread(info);
	return (0);
}
