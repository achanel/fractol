/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:39:52 by achanel           #+#    #+#             */
/*   Updated: 2021/08/28 10:39:54 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	change_color(int keycode, t_fract *fractal)
{
	fractal->color_shift += 1;
	draw_fractal(fractal);
	return (0);
}

int	change_iteration(int keycode, t_fract *fractal)
{
	if (keycode == NUM_PLUS)
		fractal->max_iteration *= 2;
	else if (keycode == NUM_MINUS)
		if (fractal->max_iteration > 2)
			fractal->max_iteration /= 2;
	draw_fractal(fractal);
	return (0);
}

int	ft_move(int keycode, t_fract *fractal)
{
	if (keycode == ARROW_DOWN)
		fractal->move_y += 1.1 / fractal->zoom;
	else if (keycode == ARROW_UP)
		fractal->move_y -= 1.1 / fractal->zoom;
	else if (keycode == ARROW_RIGHT)
		fractal->move_x += 1.1 / fractal->zoom;
	else if (keycode == ARROW_LEFT)
		fractal->move_x -= 1.1 / fractal->zoom;
	draw_fractal(fractal);
	return (0);
}

int	ft_zoom(int keycode, int x, int y, t_fract *fractal)
{
	if (keycode == SCROLL_DOWN)
		fractal->zoom += pow(1.001, 700);
	else if (keycode == SCROLL_UP)
		fractal->zoom /= pow(1.001, 700);
	draw_fractal(fractal);
	return (0);
}

int	keyboard_hook(int keycode, t_fract *fractal)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_DOWN || keycode == ARROW_UP)
		ft_move(keycode, fractal);
	else if (keycode == NUM_PLUS || keycode == NUM_MINUS)
		change_iteration(keycode, fractal);
	else if (keycode == NUM_ZERO)
		change_color(keycode, fractal);
	return (0);
}
