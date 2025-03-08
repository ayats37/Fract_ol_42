/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:20:02 by taya              #+#    #+#             */
/*   Updated: 2025/03/08 15:24:36 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	validate_input(int argc, char **argv)
{
	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
				"julia") != 0 && ft_strcmp(argv[1], "tricorn") != 0))
	{
		perror("Usage: ./fractol [mandelbrot | julia | tricorn]\n");
		exit(1);
	}
}

void	fractal_parameters(t_data *data, t_fractal *fractal, int argc,
		char **argv)
{
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc == 4 && is_valid_nbr(argv[2]) && is_valid_nbr(argv[3]))
		{
			fractal->julia.real = ft_atof(argv[2]);
			fractal->julia.imag = ft_atof(argv[3]);
		}
		else if (argc == 2)
		{
			fractal->julia.real = -0.8;
			fractal->julia.imag = 0.156;
		}
		else
		{
			perror("Error: no valid nbr");
			exit(1);
		}
		data->fractal_type = 1;
	}
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		data->fractal_type = 2;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->fractal_type = 0;
}

void	fractal_type(t_data *data, t_fractal *fractal, int argc, char **argv)
{
	validate_input(argc, argv);
	fractal_parameters(data, fractal, argc, argv);
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
	else if (data.fractal_type == 2 && argc == 2)
		tricorn(&data);
	else
		exit(1);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
