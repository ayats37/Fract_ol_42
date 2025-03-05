/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:58:17 by taya              #+#    #+#             */
/*   Updated: 2025/02/27 09:54:23 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_complex
{
	double		real;
	double		imag;

}				t_complex;

typedef struct s_fractal
{
	int			max_iterations;
	double		zoom;
	t_complex	ofsset;
	t_complex	julia;
}				t_fractal;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			fractal_type;
	t_fractal	*fractal;
}				t_data;

typedef struct s_atof_data
{
	double		sign;
	double		result;
	double		fraction;
}				t_atof_data;

void			put_pixel_to_image(t_data *data, int x, int y, int color);
int				create_window_img(t_data *data);
int				close_window(t_data *data);
void			mandelbrot(t_data *data);
int				get_color(int iteration, int max_iterations);
int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
void			julia(t_data *data, t_fractal *fractal);
void			draw_fractal(t_data *data, int px, int py, t_complex c);
void			calculate_iterations(int *iteration, int max_iterations,
					t_complex *z, t_complex c);
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atof(const char *str);
void			draw_m_fractal(t_data *data, int px, int py, t_complex z);
void			fractal_type(t_data *data, t_fractal *fractal, int argc,
					char **argv);
int				ft_atoi(const char *str);

#endif
