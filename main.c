/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:12:51 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/19 04:37:32 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void	error_message(void)
{
	ft_printf("Choose a fractal type as argument:\n\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia <x> <y>*\n\n");
	ft_printf("*x and y must be float point numbers between 2.0 and -2.0\n");
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atodbl(av[2]);
			fractal.julia_y = ft_atodbl(av[3]);
		}
		data_init(&fractal);
		image_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		error_message();
		return (3);
	}
}
