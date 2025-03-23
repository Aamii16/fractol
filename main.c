/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:27:54 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/23 08:39:04 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_init(t_fractal *fractal)
{
	fractal->c.re = 0;
	fractal->c.im = 0;
	fractal->mlx = mlx_init();
	fractal->zoom = 1;
	fractal->name = 0;
	if (!fractal->mlx)
		return (mlx_destroy_display(fractal->mlx), -1);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Amina azia");
	if (!fractal->window)
		return(mlx_destroy_window(fractal->mlx, fractal->window), mlx_destroy_display(fractal->mlx),
				put_error("Allocation Error\n"), -1);
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img)
		return(destroy_fractal(fractal), put_error("Allocation Error\n"), -1);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
						&fractal->img.line_length, &fractal->img.endian);
	return (1);
}

void	fractal_destroy(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
}

int main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && ft_strcmp(av[1], "m"))
		fractal.name = 'm';
	else if (ac == 4 && ft_strcmp(av[1], "j"))
	{
		if(!check(av[2] || !check(av[1])))
			return(put_error("Invalid Coordinates input\n"), 0);
		fractal.name = 'j';
		fractal.c.re = ft_atof(av[2]);
		fractal.c.im = ft_atof(av[3]);
	}
	else
		return(put_error("invalid argument use \nfor Mandelbrot : 'm'\n For Julia : 'j' 'x' 'y' \n"), 0);
	//fractal_init(&fractal);	
	//draw_julia(&fractal);
	//mlx_put_image_to_window(fractal.mlx, fractal.window, fractal.img.img, 0, 0);	
	//mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	//mlx_loop(fractal.mlx);
}
