/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:58:20 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/19 04:38:31 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double convert(int pixel, double min, double max, int size)
{
    return min + (pixel / (double)size) * (max - min);
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

double ft_atodbl(char *str)
{
    double result;
    double factor;
    int    i;
    int    sign;

    i = 0;
    result = 0;
    sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        factor = 0.1;
        while (str[i] >= '0' && str[i] <= '9')
        {
            result += (str[i] - '0') * factor;
            factor *= 0.1;
            i++;
        }
    }
    return (result * sign);
}
