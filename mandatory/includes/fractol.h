/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:16 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/18 14:00:42 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <stdint.h>
# include <stdio.h>

// pour read
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_tab
{
	void		*mlx;
	void		*mlx_win;
}				t_tab;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_double
{
	double		i;
	double		r;
}				t_double;

typedef struct s_zoom
{
	double		x;
	double		y;
}				t_zoom;

typedef struct s_scale
{
	double		current;
	double		zoomed;
}				t_scale;

typedef struct s_colors
{
	u_int8_t	r1;
	u_int8_t	g1;
	u_int8_t	b1;
	u_int8_t	r2;
	u_int8_t	g2;
	u_int8_t	b2;
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	index;
	double		ratio;
	double		local_ratio;
}				t_colors;

typedef struct s_settings
{
	t_data		img;
	t_pos		pos;
	t_zoom		zoom;
	t_tab		tab;
	t_pos		mouse;
	t_scale		scale;
	t_double	julia;
	t_double	mandelbrot;
	int			iterations;
	int			rewrite;
}				t_settings;

void			ft_fractol(t_settings *settings, char *fractale);
void			ft_get_mandlebrot(t_settings *settings);

void			fractol_mandlebrot(t_settings *settings);
void			ft_display_fractol(t_settings *settings, int mouse_hook(int,
						int, int, void *), int key_hook(int, void *));

void			fractol_julia(t_settings *settings);
void			ft_get_julia(t_settings *settings);

// SCREEN
void			ft_get_img(t_settings *settings);
void			ft_init_tab(t_tab *tab);
void			ft_rescale(t_settings *settings);
void			ft_zoom_in(t_settings *settings);
void			ft_zoom_out(t_settings *settings);
int				mouse_hook_mandlebrot(int keycode, int x, int y, void *param);

void			my_mlx_pixel_put(t_settings *settings, int color);

// COLORS
int				ft_color_shift(u_int32_t color1, uint32_t color2,
					t_colors *colors);
uint32_t		ft_get_color(int iteration, int max_iteration);

// HOOK
int				mouse_hook_mandlebrot(int keycode, int x, int y, void *param);
int				key_hook_mandelbrot(int keycode, void *param);
int				mouse_hook_julia(int keycode, int x, int y, void *param);
int				key_hook_julia(int keycode, void *param);

// UTILS
int				ft_parse(int argc, char **argv);
void			ft_init_value(t_settings *settings, char **argv, int argc);
int				cleanup_exit(void *settings);
int				ft_count_after_dot(char *str);

// PARSING
void			ft_initiate_parsing(int argc, char **argv);

// ATOD
double			ft_atod(char *str);

// BONUS
//void			ft_init_historic(int params);

#endif
