/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:58:08 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 12:41:18 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_get_mandlebrot(t_settings *settings)
{
	unsigned int	rgb;
	int				i;
	t_double		old;
	t_double		zoomed;

	settings->mandelbrot.r = ((settings->pos.x - 800 / 2) / (800
				* settings->scale.zoomed / 4.0)) + settings->zoom.x;
	settings->mandelbrot.i = ((settings->pos.y - 600 / 2) / (600
				* settings->scale.zoomed / 4.0)) + settings->zoom.y;
	zoomed.r = 0;
	zoomed.i = 0;
	i = 0;
	while ((zoomed.r * zoomed.r) + (zoomed.i * zoomed.i) < 4.0
		&& i <= settings->iterations)
	{
		old.r = zoomed.r;
		old.i = zoomed.i;
		zoomed.r = (old.r * old.r) - (old.i * old.i) + settings->mandelbrot.r;
		zoomed.i = 2.0 * old.r * old.i + settings->mandelbrot.i;
		i++;
	}
	rgb = ft_get_color(i, settings->iterations);
	my_mlx_pixel_put(settings, rgb);
}

void	fractol_mandlebrot(t_settings *settings)
{
	if (settings->rewrite == 1)
	{
		settings->pos.x = -1;
		settings->pos.y = -1;
		while (settings->pos.y++ < 600)
		{
			while (settings->pos.x++ < 800)
				ft_get_mandlebrot(settings);
			settings->pos.x = -1;
		}
		ft_display_fractol(settings, mouse_hook_mandlebrot,
			key_hook_mandelbrot);
		settings->rewrite = 0;
	}
}
