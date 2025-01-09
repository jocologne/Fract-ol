/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:12:51 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/09 15:02:52 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void print_error()
{
	ft_printf("Choose a fractal type:\n\n");
	ft_printf("M for Mandelbrot\n");
	ft_printf("J <x> <y> for Julia*\n\n");
	ft_printf("*x and y must be float point numbers between 2.0 and -2.0\n");
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		print_error();
		return(1);
	}
	if (argv[1][0] == 'M')
		ft_printf("Mandelbrot");
	else if (argv[1][0] == 'J')
	{
		if (argc != 4 || atoi(argv[2]) > 2 || atoi(argv[2]) < -2 || atoi(argv[3]) > 2 || atoi(argv[3]) < -2)
		{
			print_error();
			return(3);
		}
		ft_printf("Julia");
	}
	else
		print_error();	
}