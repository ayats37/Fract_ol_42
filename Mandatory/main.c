/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:59 by taya              #+#    #+#             */
/*   Updated: 2025/03/08 13:12:07 by taya             ###   ########.fr       */
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
			if (!is_valid_nbr(argv[2]) && !is_valid_nbr(argv[3]))
			{
				perror("Error: set valid numbers");
				exit(1);
			}
			fractal->julia.real = ft_atof(argv[2]);
			fractal->julia.imag = ft_atof(argv[3]);
		}
		else if (argc == 2)
		{
			fractal->julia.real = -0.8;
			fractal->julia.imag = 0.156;
		}
		else
			exit(1);
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
	fractal_type(&data, &fractal, argc, argv);
	if (!create_window_img(&data))
		return (1);
	if (data.fractal_type == 0 && argc == 2)
		mandelbrot(&data);
	else if (data.fractal_type == 1)
		julia(&data, &fractal);
	else
		exit(1);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
