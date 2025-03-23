/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:32:13 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/23 08:36:12 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_fractal *fractal)
{
	if (fractal->name == 'm')
		draw_mandelbrot(fractal);
	else if (fractal->name == 'j')
		draw_julia(fractal);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom *= 1.5;
	else if (button == 5)
		fractal->zoom /= 1.5;
	draw_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->img.img, 0, 0);
	return (0);
}

double	scale(double x, double zoom_f, double axis)
{
	return ((x - axis / 2) * (4 * zoom_f / axis));
}

int	set_color(int i)
{
	int		r;
	int		g;
	int		b;
	int		color;

	r = (i * 9) % 256;
	g = (i * 1) % 256;
	b = (i * 9) % 256;
	color = r << 16 | g << 8 | b;
	return (color);
}
