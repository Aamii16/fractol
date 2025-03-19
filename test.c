/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:47:12 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/19 23:57:36 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./minilibx-linux/mlx.h"
#include "fractol.h"

int mandelbrot_set(double cx, double cy, int max_iter)
{
	t_complex	z;
	int			i;
	double		tmpx;

	i = 0;		
	z.re = 0;
	z.im = 0;
	while(i < max_iter)
	{
		tmpx = (z.re * z.re) - (z.im * z.im) + cx;
		z.im = (2 * z.re * z.im) + cy;
		z.re = tmpx;
		if (fabs((z.re * z.re) + (z.im * z.im)) >= 4)
			break;
		i++;
	}
	return (i);
}


double	scale_x(double x, double zoom_f)
{
	double	maxx;
	double	minx;

	maxx = 2;
	minx = -2;
	return ((x - minx) / (zoom_f * (maxx - minx) / WIDTH));
}
double	scale_y(double y, double zoom_f)
{
	double	maxy;
	double	miny;
	
	maxy = 1;
	miny = -1;
	return (y - miny) / (zoom_f * (maxy - miny) / HEIGHT);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;
	int	i;
	int	iterations;

	
	x = 0;
	i = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iterations = mandelbrot_set(scale_x(x, 1), scale_y(y, 1), MAX_ITERATIONS);
			if (i <= MAX_ITERATIONS)
				put_pixel(&fractal->img, x, y, 0x000000);
			else
				put_pixel(&fractal->img, x, y, 0x0000FF);
			y++;
		}
		x++;
	}
}

int main()
{
	t_fractal	fractal;
	
	fractal_init(&fractal);	
	draw_mandelbrot(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.window, fractal.img.img, 0, 0);	
	mlx_loop(fractal.mlx);
}