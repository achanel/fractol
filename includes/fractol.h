/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:44:07 by achanel           #+#    #+#             */
/*   Updated: 2021/09/13 10:12:02 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define NUM_PLUS 69
# define NUM_MINUS 78
# define NUM_ZERO 82
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define KEY_ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_color
{
	int8_t		chanel[4];
}				t_color;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_fract
{	
	void		*mlx;
	void		*mlx_win;

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			max_iteration;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	k;
	int			x;
	int			y;
	int			name;
	int			color_shift;

	double		zoom;
	double		move_x;
	double		move_y;
}				t_fract;

void		my_mlx_pixel_put(t_fract *fractal, t_color color);
void		get_color(int iteration, t_fract *fractal);

void		draw_fractal(t_fract *fractal);
void		draw_mandelbrot(t_fract *fractal);
void		draw_julia(t_fract *fractal);
void		draw_celtic_perpendicular(t_fract *fractal);

int			change_color(int keycode, t_fract *fractal);
int			change_iteration(int keycode, t_fract *fractal);
int			ft_move(int keycode, t_fract *fractal);
int			ft_zoom(int keycode, int x, int y, t_fract *fractal);
int			keyboard_hook(int keycode, t_fract *fractal);

t_complex	init_complex(double re, double im);
void		default_values(int ac, char **av, t_fract *fractal);

#endif
