/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:12:32 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/22 22:34:35 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 100
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <unistd.h>
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
}			t_fractal;

void	put_pixel(t_data *data, int x, int y, int color);
void	fractal_init(t_fractal *fractal);
int    set_color(int i);

#endif