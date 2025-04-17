/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:21:54 by noa               #+#    #+#             */
/*   Updated: 2025/03/18 12:41:46 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// reflechir a ce que je fais si y'a des virgules

int	cleanup_exit(void *params)
{
	t_settings	*settings;

	settings = (t_settings *)params;
	if (settings->img.img)
		mlx_destroy_image(settings->tab.mlx, settings->img.img);
	if (settings->tab.mlx_win)
		mlx_destroy_window(settings->tab.mlx, settings->tab.mlx_win);
	if (settings->tab.mlx)
	{
		mlx_destroy_display(settings->tab.mlx);
		free(settings->tab.mlx);
	}
	exit(EXIT_SUCCESS);
}
