/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:54:31 by noa               #+#    #+#             */
/*   Updated: 2025/03/18 11:01:34 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_in(t_settings *settings)
{
	settings->scale.current = settings->scale.zoomed;
	settings->scale.zoomed *= 1.5;
}

void	ft_zoom_out(t_settings *settings)
{
	settings->scale.current = settings->scale.zoomed;
	settings->scale.zoomed *= 0.5;
	if (settings->scale.zoomed < 0.01)
		settings->scale.zoomed = 0.01;
}
