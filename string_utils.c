/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 05:36:12 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/26 09:02:52 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		//(unsigned char)s1[i];
		//(unsigned char)s2[i];
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_coord(char *str)
{
	int	i;

	i = 0;
	while (*str && *str == ' ')
		str++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	return (1);
}

float	ft_atof(char *str)
{
	double (sign), (num), (fract), (i);
	fract = 0.0;
	sign = 1.0;
	num = 0.0;
	i = 10.0;
	while(*str && *str == ' ')
		str++;
	if (*str == '-')
		sign = -1.0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		fract = fract + ((*str - '0') / i);
		str++;
		i *= 10.0;
	}
	return ((float)((num + fract) * sign));
}

void	put_error(char *str)
{
	while (*str)
	{
		write(1, str, 2);
		str++;
	}
}
