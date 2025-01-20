/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:58:20 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/20 17:46:44 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	convert(int pixel, double min, double max, int size)
{
	return (min + (pixel / (double)size) * (max - min));
}

t_complex	sum(t_complex n1, t_complex n2)
{
	t_complex	result;

	result.x = n1.x + n2.x;
	result.y = n1.y + n2.y;
	return (result);
}

t_complex	square(t_complex n)
{
	t_complex	result;

	result.x = (n.x * n.x) - (n.y * n.y);
	result.y = 2 * n.x * n.y;
	return (result);
}

double	ft_atodbl(char *str)
{
	double	result;
	double	factor;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + ((*str++) - '0');
	if (*str == '.')
	{
		str++;
		factor = 0.1;
		while (*str >= '0' && *str <= '9')
		{
			result += (*str - '0') * factor;
			factor *= 0.1;
			str++;
		}
	}
	return (result * sign);
}
