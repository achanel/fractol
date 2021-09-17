/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:40:04 by achanel           #+#    #+#             */
/*   Updated: 2021/08/28 10:40:05 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	default_values(int ac, char **av, t_fract *fractal)
{
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->min = init_complex(-2.0, -2.0);
	fractal->max.re = 2.0;
	fractal->max.im = fractal->min.im
		+ (fractal->min.re - fractal->min.re) * HEIGHT / WIDTH;
	fractal->max_iteration = 64;
	if (av[2])
		fractal->max_iteration = ft_atoi(av[2]);
	fractal->k = init_complex(-0.4, 0.6);
	if (av[2] && av[3] && av[4])
		fractal->k = init_complex(ft_atof(av[3]), ft_atof(av[4]));
}
