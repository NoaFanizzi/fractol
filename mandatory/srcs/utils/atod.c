/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:31:49 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 11:18:30 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_count_after_dot(char *str)
{
	size_t	i;
	int		dot;

	dot = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot = i;
		i++;
	}
	return (dot);
}

double	ft_adjust_double_conversion(double result, int dot, int length)
{
	while (dot < length - 1)
	{
		result *= 0.1;
		dot++;
	}
	return (result);
}

double	ft_convert_in_double(char *str)
{
	size_t	i;
	int		s;
	double	result;

	i = 0;
	result = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))
	{
		if (str[i] == '.')
			i++;
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (s < 0)
		result *= -1;
	return (result);
}

double	ft_atod(char *str)
{
	int		dot;
	int		length;
	double	result;

	length = ft_strlen(str);
	dot = ft_count_after_dot(str);
	result = ft_convert_in_double(str);
	result = ft_adjust_double_conversion(result, dot, length);
	return (result);
}
