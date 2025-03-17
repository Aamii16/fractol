/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:12:32 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/17 03:40:14 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 1000
#define HEIGHT 800

#include <stdio.h>
# include <mlx.h>
#include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;



typedef struct s_fractal
{
	double	x;
	double	y;
	
	
}			t_fractal;	

void	put_pixel(t_data *data, int x, int y, int color);

#endif