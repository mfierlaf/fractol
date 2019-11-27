/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:56:55 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/23 14:56:57 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol		*start_julia(t_fractol *info)
{
	info->x = 0;
	info->x2 = 1;
	info->y2 = 1.2;
	info->image_x = WHIGH;
	info->image_y = WWIDT;
	info->it_max = 50;
	info->x1 = -1;
	info->y1 = -1.2;
	info->zoom_x = info->image_x / (info->x2 - info->x1);
	info->zoom_y = info->image_y / (info->y2 - info->y1);
	return (info);
}

static void		draw(t_fractol *info)
{
	int i;

	info->c_r = -0.8;
	info->c_i = 0.156;
	info->z_r = info->x / info->zoom_x + info->x1;
	info->z_i = info->y / info->zoom_y + info->y1;
	i = 0;
	while (info->z_r * info->z_r + info->z_i * info->z_i < 4 &&
		i < info->it_max)
	{
		info->tmp = info->z_r;
		info->z_r = info->z_r * info->z_r - info->z_i * info->z_i +
		info->c_r + info->modx;
		info->z_i = 2 * info->z_i * info->tmp + info->c_i + info->mody;
		i = i + 1;
	}
	if (i == info->it_max)
		info->img_int[info->x + info->y * WHIGH] = 0x000000;
	else
		info->img_int[info->x + info->y * WHIGH] = info->color * i * 10;
}

static void		*julia(void *data)
{
	t_fractol	*info;
	int			tmp2;

	info = (t_fractol *)data;
	tmp2 = info->y;
	while (info->x < WHIGH)
	{
		info->y = tmp2;
		while (info->y < info->max_y)
		{
			draw(info);
			info->y++;
		}
		info->x++;
	}
	return (data);
}

void			julia_pthread(t_fractol *info)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)info, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].max_y = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
}
