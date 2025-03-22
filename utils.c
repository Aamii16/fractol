/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:32:13 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/22 22:28:41 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
void	put_error(char	*str)
{
	while (*str)
	{
		write(1, str, 2);
		str++;
	}
}

void	fractal_init(t_fractal *fractal)
{
	fractal->c.re = 0;
	fractal->c.im = 0;
	fractal->mlx = mlx_init();
	fractal->zoom = 1;
	//if (!fractal->mlx)
		//return ()
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Amina azia");
	//if (!fractal->window)
		//return();
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	//if (!fractal->img.img)
		//return ()
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
									 &fractal->img.line_length, &fractal->img.endian);
	//if (!fractal->img.addr)
		//return(put_error("Error retrieving data"));
}
int set_color(int i)
{
    int r;
    int g;
    int b;
    int color;

    r = (i * 9) % 256; // Increase the multiplier for red
    g = (i * 1) % 256; // Decrease the multiplier for green
    b = (i * 9) % 256; // Increase the multiplier for blue
    color = r << 16 | g << 8 | b;
    return color;
}
/*void	fractal_destroy(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
}*/// 00000000 00000000 00000000