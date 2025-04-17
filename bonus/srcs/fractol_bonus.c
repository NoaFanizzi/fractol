/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:16:43 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 13:27:35 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_display_fractol(t_settings *settings, int mouse_hook(int, int, int,
			void *), int key_hook(int, void *))
{
	mlx_put_image_to_window(settings->tab.mlx, settings->tab.mlx_win,
		settings->img.img, 0, 0);
	mlx_mouse_hook(settings->tab.mlx_win, mouse_hook, (void *)settings);
	mlx_key_hook(settings->tab.mlx_win, key_hook, (void *)settings);
	mlx_hook(settings->tab.mlx_win, 17, 0, cleanup_exit, (void *)settings);
}

void	ft_init_value(t_settings *settings, char **argv, int argc)
{
	settings->mouse.x = 1;
	settings->mouse.y = 1;
	settings->zoom.x = -0.5;
	settings->zoom.y = 0;
	settings->pos.x = -1;
	settings->pos.y = -1;
	settings->scale.current = 1.0;
	settings->scale.zoomed = 1.0;
	settings->iterations = 100;
	settings->rewrite = 1;
	if (ft_strncmp(argv[1], "Julia", 6) == 0 && argc == 4)
	{
		settings->julia.r = ft_atod(argv[2]);
		settings->julia.i = ft_atod(argv[3]);
	}
	else
	{
		settings->julia.r = -0.7;
		settings->julia.i = 0.27015;
	}
}

void	ft_fractol(t_settings *settings, char *fractale)
{
	if (settings->pos.x == -1)
		ft_init_tab(&settings->tab);
	ft_get_img(settings);
	ft_rescale(settings);
	if (ft_strncmp(fractale, "Mandelbrot", 10) == 0)
	{
		ft_init_historic(1);
		fractol_mandlebrot(settings);
	}
	if (ft_strncmp(fractale, "Julia", 5) == 0)
	{
		ft_init_historic(2);
		fractol_julia(settings);
	}
	mlx_loop(settings->tab.mlx);
}
