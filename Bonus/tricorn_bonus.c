/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:56:29 by taya              #+#    #+#             */
/*   Updated: 2025/02/25 01:57:11 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_iter_tricorn(int *iteration, int max_iterations, t_complex *z,
		t_complex c)
{
	double	tmp_real;

	while (*iteration < max_iterations && ((z->real * z->real + z->imag
				* z->imag) <= 4))
	{
		tmp_real = z->real * z->real - z->imag * z->imag + c.real;
		z->imag = -2 * z->real * z->imag + c.imag;
		z->real = tmp_real;
		(*iteration)++;
	}
}

void	draw_t_fractal(t_data *data, int px, int py, t_complex z)
{
	t_complex	c;
	int			iteration;
	int			color;

	c.real = (px - data->width / 2) / data->fractal->zoom
		+ data->fractal->ofsset.real;
	c.imag = (py - data->height / 2) / data->fractal->zoom
		+ data->fractal->ofsset.imag;
	iteration = 0;
	calculate_iter_tricorn(&iteration, data->fractal->max_iterations, &z, c);
	color = get_color(iteration, data->fractal->max_iterations);
	put_pixel_to_image(data, px, py, color);
}

void	tricorn(t_data *data)
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
			draw_t_fractal(data, px, py, z);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
