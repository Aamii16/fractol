/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:12:32 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/28 06:55:54 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 150
# include <stdio.h>
# include <mlx.h>
//# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;	

typedef struct s_fractal
{
	void		*mlx;
	void		*window;
	t_data		img;
	t_complex	c;
	double		zoom;
	char		name;
}			t_fractal;
//string utils 
int		ft_strcmp(char *s1, char *s2);
int		check_coord(char *str);
float	ft_atof(char *str);
void	put_error(char *str);
// rendering utils
void	put_pixel(t_data *data, int x, int y, int color);
void	draw_fractal(t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		set_color(int i);
int		set_color_2(int i);

double	scale(double x, double zoom_f, double axis);
//fractal set
void	destroy_fractal(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);

void	draw_mandelbrot(t_fractal *fractal);
int		key_hook(int keycode, t_fractal *fractal);
int		exit_hook(t_fractal *fractal);

#endif