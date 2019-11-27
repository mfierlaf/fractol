/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:29:36 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/22 17:29:38 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	key_push_swap(int key2, void *param)
{
	t_fractol	*info;
	int			(*key)(int, void*);

	key = &key_push;
	info = param;
	if (key2 == J_KEY)
	{
		info->name = 2;
		info = start_julia(info);
	}
	if (key2 == M_KEY)
	{
		info->name = 1;
		info = start_mandelbrot(info);
	}
	if (key2 == B_KEY)
	{
		info->name = 3;
		info = start_burning_ship(info);
	}
	return (0);
}

int			key_push(int key2, void *param)
{
	t_fractol	*info;
	int			(*key)(int, void*);

	key = &key_push;
	info = param;
	if (key2 == ESC_KEY)
	{
		free(param);
		exit(1);
	}
	if (key2 == C_KEY)
		info->color_flag = !info->color_flag;
	if (key2 == S_KEY)
		info->move = !info->move;
	key_push_swap(key2, info);
	return (0);
}
