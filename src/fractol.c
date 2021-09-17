/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:39:44 by achanel           #+#    #+#             */
/*   Updated: 2021/08/28 10:39:46 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_args(int ac, char **av)
{
	if (ac < 2 || (ft_strncmp(av[1], "Mandelbrot", 11) != 0
			&& ft_strncmp(av[1], "Julia", 5) != 0
			&& ft_strncmp(av[1], "Celtic_Perpendicular", 20) != 0))
	{
		printf("\nAvailable Fractals:\n\nMandelbrot\nJulia\nCeltic_Perpendicular\n"
			"\nUSAGE: ./fractol <Fractal_name>\n\n"
			"AV_0 : ./fractol\n"
			"AV_1 : <Fractal name>\n"
			"AV_2 : max_iteration (from 2 to 1000)\n"
			"For Julia set:\n"
			"AV_3 : Real complex number\n"
			"AV_4 : Imaginary complex number\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("\nFor move use ARROWS\n"
			"For zoom use SCROLL\n"
			"To change iteration use NUM_PLUS and NUM_MINUS\n"
			"To change color use NUM_ZERO\n"
			"To exit use ESC\n");
}

int	main(int ac, char **av)
{
	void	*mlx;
	t_fract	*fractal;

	check_args(ac, av);
	mlx = mlx_init();
	fractal = ft_calloc(sizeof(t_fract), sizeof(t_fract));
	if (fractal == 0 || mlx == 0)
		return (0);
	fractal->mlx = mlx;
	fractal->mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, av[1]);
	default_values(ac, av, fractal);
	if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
		fractal->name = 1;
	if (ft_strncmp(av[1], "Julia", 5) == 0)
		fractal->name = 2;
	if (ft_strncmp(av[1], "Celtic_Perpendicular", 20) == 0)
		fractal->name = 3;
	draw_fractal(fractal);
	mlx_mouse_hook(fractal->mlx_win, ft_zoom, fractal);
	mlx_key_hook(fractal->mlx_win, keyboard_hook, fractal);
	mlx_loop(mlx);
	return (0);
}
