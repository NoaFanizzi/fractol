/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:01:32 by noa               #+#    #+#             */
/*   Updated: 2025/03/18 13:53:26 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook_julia(int keycode, void *param)
{
	t_settings	*settings;

	settings = (t_settings *)param;
	if (keycode == XK_Escape)
	{
		cleanup_exit((void *)settings);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 65362)
	{
		settings->rewrite = 1;
		settings->iterations += 10;
		fractol_julia(settings);
	}
	if (keycode == XK_Down && settings->iterations > 15)
	{
		settings->iterations -= 10;
		fractol_julia(settings);
	}
	return (0);
}

int	mouse_hook_julia(int keycode, int x, int y, void *param)
{
	t_settings	*settings;

	settings = (t_settings *)param;
	if (keycode == 4)
	{
		settings->rewrite = 1;
		ft_zoom_in(settings);
		ft_rescale(settings);
		fractol_julia(settings);
	}
	if (keycode == 5)
	{
		settings->rewrite = 1;
		ft_zoom_out(settings);
		ft_rescale(settings);
		fractol_julia(settings);
	}
	(void)x;
	(void)y;
	return (0);
}

int	key_hook_mandelbrot(int keycode, void *param)
{
	t_settings	*settings;

	settings = (t_settings *)param;
	if (keycode == XK_Escape)
	{
		cleanup_exit((void *)settings);
		exit(EXIT_SUCCESS);
	}
	if (keycode == XK_Up)
	{
		settings->rewrite = 1;
		settings->iterations += 10;
		fractol_mandlebrot(settings);
	}
	if (keycode == XK_Down)
	{
		settings->rewrite = 1;
		settings->iterations -= 10;
		fractol_mandlebrot(settings);
	}
	return (0);
}

int	mouse_hook_mandlebrot(int keycode, int x, int y, void *param)
{
	t_settings	*settings;

	settings = (t_settings *)param;
	if (keycode == 4)
	{
		settings->rewrite = 1;
		ft_zoom_in(settings);
		ft_rescale(settings);
		fractol_mandlebrot(settings);
	}
	if (keycode == 5)
	{
		settings->rewrite = 1;
		ft_zoom_out(settings);
		ft_rescale(settings);
		fractol_mandlebrot(settings);
	}
	(void)x;
	(void)y;
	return (0);
}
