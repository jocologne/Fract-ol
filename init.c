/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:14:21 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/19 04:50:05 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void	data_fill(t_fractal *fractal)
{
	fractal->escape_distance = 4;
	fractal->image_definition = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void events(t_fractal *fractal)
{
	mlx_hook(fractal->window, 
				DestroyNotify, 
				StructureNotifyMask, 
				close_event, 
				fractal);
	mlx_hook(fractal->window, 
				KeyPress, 
				KeyPressMask, 
				key_event, 
				fractal);
	mlx_hook(fractal->window, 
				ButtonPress, 
				ButtonPressMask, 
				mouse_event, 
				fractal);
}

void	data_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		exit (4);
	fractal->window = mlx_new_window(fractal->mlx, W, H, fractal->name);
	if (fractal->window == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit (5);
	}
	fractal->img.img_pointer = mlx_new_image(fractal->mlx, W, H);
	if (fractal->img.img_pointer == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit (6);
	}
	fractal->img.pixel_pointer = mlx_get_data_addr(fractal->img.img_pointer, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events(fractal);
	data_fill(fractal);
}
