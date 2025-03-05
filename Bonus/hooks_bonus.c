/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:23:25 by taya              #+#    #+#             */
/*   Updated: 2025/02/27 10:56:16 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	else if (keycode == 123)
		data->fractal->ofsset.real += 30 / data->fractal->zoom;
	else if (keycode == 124)
		data->fractal->ofsset.real -= 30 / data->fractal->zoom;
	else if (keycode == 125)
		data->fractal->ofsset.imag -= 30 / data->fractal->zoom;
	else if (keycode == 126)
		data->fractal->ofsset.imag += 30 / data->fractal->zoom;
	if (data->fractal_type == 0)
		mandelbrot(data);
	else if (data->fractal_type == 1)
		julia(data, data->fractal);
	else if (data->fractal_type == 2)
		tricorn(data);
	else
		return (1);
	return (0);
}

void	apply_zoom(t_data *data, int button, int x, int y)
{
	double	mouse_re;
	double	mouse_imag;

	mouse_re = (x - data->width / 2) / data->fractal->zoom
		+ data->fractal->ofsset.real;
	mouse_imag = (y - data->height / 2) / data->fractal->zoom
		+ data->fractal->ofsset.imag;
	if (button == 4)
	{
		data->fractal->zoom *= 1.1;
		data->fractal->ofsset.real = mouse_re - (x - data->width / 2)
			/ data->fractal->zoom;
		data->fractal->ofsset.imag = mouse_imag - (y - data->height / 2)
			/ data->fractal->zoom;
	}
	else if (button == 5)
	{
		data->fractal->zoom /= 1.1;
		data->fractal->ofsset.real = mouse_re - (x - data->width / 2)
			/ data->fractal->zoom;
		data->fractal->ofsset.imag = mouse_imag - (y - data->height / 2)
			/ data->fractal->zoom;
	}
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4 || button == 5)
		apply_zoom(data, button, x, y);
	if (data->fractal_type == 0)
		mandelbrot(data);
	else if (data->fractal_type == 1)
		julia(data, data->fractal);
	else if (data->fractal_type == 2)
		tricorn(data);
	else
		return (1);
	return (0);
}
