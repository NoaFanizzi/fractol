/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_settings_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:12:33 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 12:41:41 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_get_img(t_settings *settings)
{
	settings->img.img = mlx_new_image(settings->tab.mlx, 800, 600);
	if (!settings->img.img)
		exit(EXIT_FAILURE);
	settings->img.addr = mlx_get_data_addr(settings->img.img,
			&settings->img.bits_per_pixel, &settings->img.line_length,
			&settings->img.endian);
	mlx_clear_window(settings->tab.mlx, settings->tab.mlx_win);
}

void	my_mlx_pixel_put(t_settings *settings, int color)
{
	char	*dst;

	dst = settings->img.addr + (settings->pos.y * settings->img.line_length
			+ settings->pos.x * (settings->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_tab(t_tab *tab)
{
	tab->mlx = mlx_init();
	if (tab->mlx == NULL)
		exit(1);
	tab->mlx_win = mlx_new_window(tab->mlx, 800, 600, "fractol");
	if (tab->mlx_win == NULL)
	{
		mlx_destroy_display(tab->mlx);
		free(tab->mlx);
		exit(1);
	}
}

void	ft_rescale(t_settings *settings)
{
	double	ratio;

	mlx_mouse_get_pos(settings->tab.mlx, settings->tab.mlx_win,
		&settings->mouse.x, &settings->mouse.y);
	ratio = (1.0 / settings->scale.current) - (1.0 / settings->scale.zoomed);
	settings->zoom.x += (settings->mouse.x - 400.0) * (4.0 / 800.0) * ratio;
	settings->zoom.y += (settings->mouse.y - 300.0) * (4.0 / 600.0) * ratio;
}
