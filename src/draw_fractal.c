/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:39:35 by achanel           #+#    #+#             */
/*   Updated: 2021/08/28 10:39:37 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_celtic_perpendicular(t_fract *fractal)
{
	int			iteration;
	t_complex	z;

	z = init_complex(fractal->c.re, fractal->c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && iteration < fractal->max_iteration)
	{
		z = init_complex(fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractal->c.re,
				-2.0 * fabs(z.re) * z.im + fractal->c.im);
		iteration++;
	}
	get_color(iteration, fractal);
}

void	draw_julia(t_fract *fractal)
{
	int			iteration;
	t_complex	z;

	z = init_complex(fractal->c.re, fractal->c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && iteration < fractal->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fractal->k.re,
				2.0 * z.re * z.im + fractal->k.im);
		iteration++;
	}
	get_color(iteration, fractal);
}

void	draw_mandelbrot(t_fract *fractal)
{
	int			iteration;
	t_complex	z;

	z = init_complex(fractal->c.re, fractal->c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4.0 && iteration < fractal->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fractal->c.re,
				2.0 * z.re * z.im + fractal->c.im);
		iteration++;
	}
	get_color(iteration, fractal);
}

void	draw_fractal(t_fract *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	fractal->y = -1;
	while (fractal->y < HEIGHT)
	{
		fractal->x = -1;
		while (fractal->x < WIDTH)
		{
			fractal->c.re = (fractal->x - WIDTH / 2)
				* 4.0 / (fractal->zoom * WIDTH) + fractal->move_x;
			fractal->c.im = (fractal->y - HEIGHT / 2)
				* 4.0 / (fractal->zoom * WIDTH) + fractal->move_y;
			if (fractal->name == 1)
				draw_mandelbrot(fractal);
			if (fractal->name == 2)
				draw_julia(fractal);
			if (fractal->name == 3)
				draw_celtic_perpendicular(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
}
