/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:47:12 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/17 03:59:45 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./minilibx-linux/mlx.h"
#include <mlx.h>
#include "fractol.h"
/*double mandelbrot_set(double cx, double cy)
{
	double	zx;
	double	zy;
	double	tmp;
	
	zx = 0;
	zy = 0;
	while()
	{
		tmp = zx;
		zx = (zx * zx) - (zy * zy) + cx;
		zy = (2 * tmp * zy) + cy;
	}
	
}*/
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

double	scale_x(double x)
{
	return (-2 + (x / (double)WIDTH) * 4);
}
double	scale_y(double y)
{
return (-1 + (y / (double)HEIGHT) * 2);
}

int main()
{
	void	*mlx = mlx_init();
	void	*window = mlx_new_window(mlx, WIDTH, HEIGHT, "Amina azia");
	t_data	img;
	double	x, y;
	
	x = 0;
	y = 0;
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	if (!img.addr)
		return(printf("Error retrieving data"));
	while(x < 50)
	{	
		y = 0;	
		while(y < 50)
		{	
			while(x++ < 50)
				put_pixel(&img, scale_x(x), scale_y(y), 0xFF0000);
			y++;
		}
		x++;
	}
	
	mlx_put_image_to_window(mlx, window, img.img, 30, 30);	
	mlx_loop(mlx);
}