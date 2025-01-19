/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:58:20 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/18 23:30:05 by jcologne         ###   ########.fr       */
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

	result.real = n1.real + n2.real;
	result.img = n1.img + n2.img;
	return (result);
}

t_complex	square(t_complex n)
{
	t_complex	result;

	result.real = (n.real * n.real) - (n.img * n.img);
	result.img = 2 * n.real * n.img;
	return (result);
}
