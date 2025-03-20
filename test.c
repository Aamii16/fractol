/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:47:12 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/20 03:06:05 by amzahir          ###   ########.fr       */
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
	while((z.re * z.re) + (z.im * z.im) <= 4 && i < max_iter)
	{
		tmpx = (z.re * z.re) - (z.im * z.im) + cx;
		z.im = (2 * z.re * z.im) + cy;
		z.re = tmpx;
		//if ((z.re * z.re) + (z.im * z.im) <= 4)
			//break;
		i++;
	}
	return (i);
}


double	scale_x(double x, double zoom_f)
{
	return ((x - WIDTH / 2) * (zoom_f / WIDTH));
}
double	scale_y(double y, double zoom_f)
{
	return ((y - HEIGHT / 2) * (zoom_f / HEIGHT));
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;
	int	iterations;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iterations = mandelbrot_set(scale_x(x, fractal->zoom), scale_y(y, fractal->zoom), MAX_ITERATIONS);
			if (iterations == MAX_ITERATIONS)
			{
				put_pixel(&fractal->img, x, y, 0x00000000);
				//printf("Pixel set at (%d, %d) with color 0x0000000000\n", x, y);
			}
			else
				put_pixel(&fractal->img, x, y, set_color(iterations));
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