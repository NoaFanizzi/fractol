/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:11:41 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 14:19:58 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_count_dot(int argc, char **argv)
{
	size_t	i;
	int		j;
	int		dot;

	j = 2;
	dot = 0;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '.')
				dot += 1;
			if (dot > 1)
				return (1);
			i++;
		}
		j++;
		dot = 0;
	}
	return (0);
}

int	ft_check_letters(char **stack)
{
	size_t	i;
	size_t	j;

	i = 2;
	j = 0;
	while (stack[i])
	{
		while (stack[i][j])
		{
			if ((stack[i][j] == '-' || stack[i][j] == '+') && (j == 0))
				j++;
			if (ft_isdigit(stack[i][j]) == 0 && stack[i][j] != '.')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_count_number_after_dot(char **argv)
{
	size_t	i;
	size_t	j;
	size_t	amount;

	i = 0;
	j = 2;
	amount = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			while (argv[j][i] != '.' && argv[j][i])
				i++;
			amount = i;
			while (argv[j][i])
				i++;
			if (i - amount - 1 > 38)
				return (1);
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_parse(int argc, char **argv)
{
	if ((ft_strncmp(argv[1], "Julia", 6) != 0) && (ft_strncmp(argv[1],
				"Mandelbrot", 11) != 0))
	{
		ft_putstr_fd("Invalid fractal !\n", 2);
		ft_putstr_fd("You must choose between:\n-Mandelbrot\n-Julia\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	{
		if (argc != 2)
		{
			ft_putstr_fd("You cannot add any parameters with Mandelbrot !\n",
				2);
			return (1);
		}
		return (0);
	}
	if ((ft_count_dot(argc, argv) == 1 || ft_check_letters(argv) == 1)
		|| (argc == 3 || ft_count_number_after_dot(argv) == 1))
	{
		ft_putstr_fd("Please use Julia with valid parameters\n", 2);
		return (1);
	}
	else
		return (0);
}

void	ft_initiate_parsing(int argc, char **argv)
{
	t_settings	settings;

	if (ft_parse(argc, argv) == 1)
		return ;
	ft_init_value(&settings, argv, argc);
	ft_fractol(&settings, argv[1]);
}
