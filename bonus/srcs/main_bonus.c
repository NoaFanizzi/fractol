/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:04:50 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 12:41:57 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Invalid fractal !\n", 2);
		ft_putstr_fd("You must choose between:\n-Mandelbrot\n-Julia\n", 2);
		return (0);
	}
	ft_initiate_parsing(argc, argv);
}
