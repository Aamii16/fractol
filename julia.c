/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:28:02 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/28 06:26:16 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(double zx, double zy, t_complex c)
{
	int			i;
	double		tmpx;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		tmpx = (zx * zx) - (zy * zy) + c.re;
		zy = (2 * zx * zy) + c.im;
		zx = tmpx;
		if ((zx * zx) + (zy * zy) > 4)
			break ;
		i++;
	}
	return (i);
}

void	draw_julia(t_fractal *fractal)
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
			iterations = julia_set(scale(x, fractal->zoom, WIDTH),
					scale(y, fractal->zoom, HEIGHT), fractal->c);
			if (iterations == MAX_ITERATIONS)
				put_pixel(&fractal->img, x, y, 0x00000000);
			else
				put_pixel(&fractal->img, x, y, set_color_2(iterations));
			y++;
		}
		x++;
	}
}
