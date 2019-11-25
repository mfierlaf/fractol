/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:34:03 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/10/15 13:34:08 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "keynote.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define WHIGH 1200
# define WWIDT 1000

typedef struct	s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_int;
	int		x;
	int		y;
	float	tmp;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		image_x;
	int		image_y;
	int		it_max;
	float	zoom_x;
	float	zoom_y;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		bpp;
	int		lsize;
	int		endian;
	int		color;
	int		name;
	int		color_flag;
	double	modx;
	double	mody;
	int		nzoom;
}				t_fractol;

int 	key_loop_hoock(t_fractol *info);
int 	move(int x, int y, t_fractol *info);
int		main();
void	mandelbrot(t_fractol *info);
void	julia(t_fractol *info);
void	burning_ship(t_fractol *info);
int 	key_push(int key, void *param);
int		mouse_hook(int mouse2, int x, int y, t_fractol *info);
#endif
