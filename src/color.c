/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:39:24 by achanel           #+#    #+#             */
/*   Updated: 2021/08/28 10:39:27 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fract *fractal, t_color color)
{
	int	i;

	i = fractal->y * fractal->line_length + fractal->x
		* (fractal->bits_per_pixel / 8);
	fractal->addr[i] = color.chanel[0];
	fractal->addr[i++] = color.chanel[1];
	fractal->addr[i++] = color.chanel[2];
	fractal->addr[i++] = color.chanel[3];
}

void	get_color(int iteration, t_fract *fractal)
{
	double	t;
	t_color	color;

	t = (double)iteration / (double)fractal->max_iteration;
	if (iteration < fractal->max_iteration)
	{
		color.chanel[0] = 0;
		color.chanel[(0 + fractal->color_shift) % 3 + 1]
			= (int)(9 * (1 - t) * pow(t, 3) * 255);
		color.chanel[(1 + fractal->color_shift) % 3 + 1]
			= (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color.chanel[(2 + fractal->color_shift) % 3 + 1]
			= (int)(8.5 * pow((1 - t), 3) * t * 255);
		my_mlx_pixel_put(fractal, color);
	}
}
