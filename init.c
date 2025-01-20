/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:14:21 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/20 17:46:23 by jcologne         ###   ########.fr       */
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

static void	events(t_fractal *f)
{
	mlx_hook(f->window, DestroyNotify, StructureNotifyMask, close_event, f);
	mlx_hook(f->window, KeyPress, KeyPressMask, key_event, f);
	mlx_hook(f->window, ButtonPress, ButtonPressMask, mouse_event, f);
}

void	data_init(t_fractal *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit (4);
	f->window = mlx_new_window(f->mlx, W, H, f->name);
	if (f->window == NULL)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		exit (5);
	}
	f->img.img_pointer = mlx_new_image(f->mlx, W, H);
	if (f->img.img_pointer == NULL)
	{
		mlx_destroy_window(f->mlx, f->window);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		exit (6);
	}
	f->img.pixel_pointer = mlx_get_data_addr(f->img.img_pointer, &f->img.bpp, &f->img.line_len, &f->img.endian);
	events(f);
	data_fill(f);
}
