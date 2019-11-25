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

#include "fractol.h"

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
	if (key2 == J_KEY)
		info->name = 2;
	if (key2 == M_KEY)
		info->name = 1;
	if (key2 == B_KEY)
		info->name = 3;
	if (info->name == 2)
		mlx_hook(info->win, MOTIONNOTIFY, POINTERMOTIONMASK, move, info);
	return (0);
}
