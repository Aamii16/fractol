/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:32:13 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/27 06:58:40 by amzahir          ###   ########.fr       */
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
	put_error("coucou\n");
	printf("name %c", fractal->name);
	if (fractal->name == 'm')
	{
		put_error("drawn mandel\n");
		draw_mandelbrot(fractal);
		put_error("drawn mandel\n");
	}
	else if (fractal->name == 'j')
	{
		draw_julia(fractal);
		put_error("drawn julia\n");
	}
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
