/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:47:12 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/27 06:41:15 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./minilibx-linux/mlx.h"
#include "fractol.h"

int	mandelbrot_set(double cx, double cy, int max_iter)
{
	t_complex	z;
	int			i;
	double		tmpx;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < max_iter)
	{
		tmpx = (z.re * z.re) - (z.im * z.im) + cx;
		z.im = (2 * z.re * z.im) + cy;
		z.re = tmpx;
		if ((z.re * z.re) + (z.im * z.im) > 4)
			break ;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int		x;
	int		y;
	int		iterations;

	put_error("iterations\n");
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iterations = mandelbrot_set(scale(x, fractal->zoom, WIDTH),
					scale(y, fractal->zoom, HEIGHT), MAX_ITERATIONS);
			if (iterations == MAX_ITERATIONS)
				put_pixel(&fractal->img, x, y, 0x00000000);
			else
				put_pixel(&fractal->img, x, y, set_color(iterations));
			y++;
		}
		x++;
	}
}
