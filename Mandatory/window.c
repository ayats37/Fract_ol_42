/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:50 by taya              #+#    #+#             */
/*   Updated: 2025/02/27 12:51:26 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dest = data->addr + ((y * data->line_length) + (x * (data->bpp / 8)));
		*(unsigned int *)dest = color;
	}
}

int	create_window_img(t_data *data)
{
	data->width = 800;
	data->height = 700;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width, data->height,
			"fract-ol");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
	{
		mlx_destroy_window(data->mlx, data->win);
		return (0);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	return (1);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	exit(0);
	return (0);
}

int	get_color(int iteration, int max_iterations)
{
	int	color;

	if (iteration == max_iterations)
		return (0x000000);
	color = (iteration * 255 / max_iterations);
	return (((color * 2) << 16) | ((color * 4) << 8) | (color * 9));
}
