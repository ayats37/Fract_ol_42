/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:59 by taya              #+#    #+#             */
/*   Updated: 2025/03/05 12:08:21 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_type(t_data *data, t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
				"julia") != 0))
	{
		perror("Usage: ./fractol [mandelbrot | julia]");
		exit(1);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc == 4)
		{
			fractal->julia.real = ft_atof(argv[2]);
			fractal->julia.imag = ft_atof(argv[3]);
		}
		else
		{
			fractal->julia.real = -0.8;
			fractal->julia.imag = 0.156;
		}
		data->fractal_type = 1;
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->fractal_type = 0;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_fractal	fractal;

	fractal.max_iterations = 100;
	fractal.zoom = 200;
	fractal.ofsset.real = 0;
	fractal.ofsset.imag = 0;
	data.fractal = &fractal;
	if (!create_window_img(&data))
		return (1);
	fractal_type(&data, &fractal, argc, argv);
	if (data.fractal_type == 0)
		mandelbrot(&data);
	else
		julia(&data, &fractal);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
