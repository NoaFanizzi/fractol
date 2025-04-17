/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:16:42 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 14:22:22 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_color_shift(u_int32_t color1, uint32_t color2, t_colors *colors)
{
	colors->r1 = (color1 >> 16) & 0xFF;
	colors->g1 = (color1 >> 8) & 0xFF;
	colors->b1 = color1 & 0xFF;
	colors->r2 = (color2 >> 16) & 0xFF;
	colors->g2 = (color2 >> 8) & 0xFF;
	colors->b2 = color2 & 0xFF;
	colors->r = (int)((1.0 - colors->local_ratio) * colors->r1
			+ colors->local_ratio * colors->r2);
	colors->g = (int)((1.0 - colors->local_ratio) * colors->g1
			+ colors->local_ratio * colors->g2);
	colors->b = (int)((1.0 - colors->local_ratio) * colors->b1
			+ colors->local_ratio * colors->b2);
	return ((colors->r << 16) | (colors->g << 8) | colors->b);
}

uint32_t	ft_get_color(int iteration, int max_iteration)
{
	t_colors	colors;
	int			num_colors;
	uint32_t	colors_set[6];

	colors_set[0] = 0x000000;
	colors_set[1] = 0x0000FF;
	colors_set[2] = 0x00FFFF;
	colors_set[3] = 0x8000FF;
	colors_set[4] = 0xFF00FF;
	colors_set[5] = 0xFFFFFF;
	num_colors = sizeof(colors_set) / sizeof(colors_set[0]);
	if (iteration >= max_iteration)
		return (0x000000);
	colors.ratio = (double)iteration / max_iteration;
	colors.index = (int)(colors.ratio * (num_colors - 1));
	colors.local_ratio = (colors.ratio * (num_colors - 1)) - colors.index;
	return (ft_color_shift(colors_set[colors.index], colors_set[colors.index
				+ 1], &colors));
}
