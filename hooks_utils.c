/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:51:28 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/27 05:44:16 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
	{
		destroy_fractal(fractal);
		exit(0);
	}
	return (0);
}

int	exit_hook(t_fractal *fractal)
{
	destroy_fractal(fractal);
	exit(0);
	return (0);
}