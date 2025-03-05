/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:29:44 by taya              #+#    #+#             */
/*   Updated: 2025/02/25 01:42:50 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw_fractal(t_data *data, int px, int py, t_complex c)
{
	t_complex	z;
	int			iteration;
	int			color;

	z.real = (px - data->width / 2) / data->fractal->zoom
		+ data->fractal->ofsset.real;
	z.imag = (py - data->height / 2) / data->fractal->zoom
		+ data->fractal->ofsset.imag;
	iteration = 0;
	calculate_iterations(&iteration, data->fractal->max_iterations, &z, c);
	color = get_color(iteration, data->fractal->max_iterations);
	put_pixel_to_image(data, px, py, color);
}

void	julia(t_data *data, t_fractal *fractal)
{
	int			px;
	int			py;
	t_complex	c;

	py = 0;
	while (py < data->height)
	{
		px = 0;
		while (px < data->width)
		{
			c.real = fractal->julia.real;
			c.imag = fractal->julia.imag;
			draw_fractal(data, px, py, c);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
