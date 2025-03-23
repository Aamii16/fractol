/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 05:36:12 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/23 06:21:44 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

float	atof(char *str)
{
	double (sign), (num), (fract), (i);
	fract = 0.0;
	sign = 1.0;
	num = 0.0;
	i = 10.0;
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
	{
		str++;
		while (*str && (*str >= '0' && *str <= '9'))
		{
			fract = fract + ((*str - '0') / i);
			str++;
			printf("%f\n", fract);
			i *= 10.0;
		}
	}
	printf("%f\n", fract);
	num += fract;
	return ((float)num);
}

int main()
{
	printf("%f\n", atof("-1011.10"));
	
}