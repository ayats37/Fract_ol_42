/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:56 by taya              #+#    #+#             */
/*   Updated: 2025/02/25 01:40:44 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_m_fractal(t_data *data, int px, int py, t_complex z)
{
	t_complex	c;
	int			iteration;
	int			color;

	c.real = (px - data->width / 2) / data->fractal->zoom
		+ data->fractal->ofsset.real;
	c.imag = (py - data->height / 2) / data->fractal->zoom
		+ data->fractal->ofsset.imag;
	iteration = 0;
	calculate_iterations(&iteration, data->fractal->max_iterations, &z, c);
	color = get_color(iteration, data->fractal->max_iterations);
	put_pixel_to_image(data, px, py, color);
}

void	mandelbrot(t_data *data)
{
	int			py;
	int			px;
	t_complex	z;

	py = 0;
	while (py < data->height)
	{
		px = 0;
		while (px < data->width)
		{
			z.real = 0;
			z.imag = 0;
			draw_m_fractal(data, px, py, z);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
