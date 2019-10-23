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
	t_mlx	*mlx;
	int		(*key)(int, void*);

	key = &key_push;
	mlx = param;
	if (key2 == ESC_KEY)
	{
		free(param);
		exit(1);
	}
