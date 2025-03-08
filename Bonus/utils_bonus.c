/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:31:44 by taya              #+#    #+#             */
/*   Updated: 2025/03/08 14:54:13 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}

double	ft_atof(const char *str)
{
	t_atof_data	data_atof;

	data_atof.result = 0;
	data_atof.sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			data_atof.sign *= -1;
	data_atof.result = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '.')
	{
		data_atof.fraction = 0.1;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			data_atof.result += (*str - '0') * data_atof.fraction;
			data_atof.fraction /= 10;
			str++;
		}
	}
	return (data_atof.sign * data_atof.result);
}

void	calculate_iterations(int *iteration, int max_iterations, t_complex *z,
		t_complex c)
{
	double	tmp_real;

	while (*iteration < max_iterations && (z->real * z->real + z->imag
			* z->imag <= 4))
	{
		tmp_real = z->real * z->real - z->imag * z->imag + c.real;
		z->imag = 2 * z->real * z->imag + c.imag;
		z->real = tmp_real;
		(*iteration)++;
	}
}

int	is_valid_nbr(char *str)
{
	int i ;
	i = 0 ;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return 0;
		i++;
	}
	return 1;
}
