/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:20:48 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 12:55:11 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_init_historic(int params)
{
	int		fd;
	char	*buffer;

	if (params == 1)
	{
		fd = open("bonus/srcs/descriptions/mandelbrot.txt", O_RDONLY);
		if (!fd)
			return ;
	}
	if (params == 2)
	{
		fd = open("bonus/srcs/descriptions/julia.txt", O_RDONLY);
		if (!fd)
			return ;
	}
	buffer = get_next_line(fd);
	ft_putstr_fd(buffer, 1);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		ft_putstr_fd(buffer, 1);
	}
	free(buffer);
}
